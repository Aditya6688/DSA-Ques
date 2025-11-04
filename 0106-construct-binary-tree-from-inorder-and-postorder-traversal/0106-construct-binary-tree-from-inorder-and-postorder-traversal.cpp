/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(vector<int>& inorder, vector<int>& postorder, int is, int ie, int &pi) {
        int ind = 0;
        if (is > ie)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[pi--]);

        for (int i = is; i <= ie; i++) {
            if (inorder[i] == root->val) {
                ind = i;
                break;
            }
        }

        root->right = func(inorder, postorder, ind + 1, ie,pi);
        root->left = func(inorder, postorder, is, ind - 1,pi);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pi = inorder.size()-1;
        int m = inorder.size();
        return func(inorder,postorder,0,m-1,pi);
    }
};