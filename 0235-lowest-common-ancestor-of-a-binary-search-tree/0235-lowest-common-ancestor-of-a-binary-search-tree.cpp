/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // int func(TreeNode* &root, TreeNode* &p, TreeNode* &q){
    //     if(!root) return NULL;

    //     if(p == root || q == root) return root->val;

    //     int left = func(root->left,p,q);
    //     int right = func(root->right,p,q);

    //     if(left && right) return root->val;
    //     else (!left)?right:left;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        if(p == root || q == root) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;
        else{
            if(!left) return right;
            else return left;
        }
    }
};