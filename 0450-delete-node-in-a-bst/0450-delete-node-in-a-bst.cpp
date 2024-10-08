/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        // Loop down to find the leftmost leaf
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root; // If the tree is empty or we reach a null node
        
        // Step 1: Search for the node to be deleted
        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Search in the left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Search in the right subtree
        } else {
            // Step 2: Node found, perform deletion
            // Case 1: Node with only one child or no child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root; // Free memory
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root; // Free memory
                return temp;
            }

            // Case 2: Node with two children
            // Find the in-order successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(root->right);

            // Replace the node's value with the in-order successor's value
            root->val = temp->val;

            // Delete the in-order successor
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};