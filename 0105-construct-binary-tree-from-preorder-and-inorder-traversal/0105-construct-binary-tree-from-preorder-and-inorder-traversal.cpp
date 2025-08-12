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
    int pi = 0;
    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int is, int ie){
        if(is>ie) return NULL;
        TreeNode* curr = new TreeNode(preorder[pi++]);

        int inind;
        for(int i=is;i<=ie;i++){
            if(inorder[i] == curr->val){
                inind = i;
                break;
            }
        }

        curr->left = func(preorder, inorder, is, inind-1);
        curr->right = func(preorder, inorder, inind+1, ie);

        return curr;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = func(preorder, inorder, 0,inorder.size()-1);
        return res;
    }
};