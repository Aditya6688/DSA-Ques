/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "# ";   // use # for NULL
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(istringstream &ss) {
        string val;
        ss >> val;                // read next token
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = helper(ss);
        node->right = helper(ss);
        return node;
    }
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));