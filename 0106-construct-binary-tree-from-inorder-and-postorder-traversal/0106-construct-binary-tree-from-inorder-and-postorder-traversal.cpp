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
    TreeNode* func(vector<int>& inorder, vector<int>& postorder, int is, int ie, int &pi){
        if(is>ie) return NULL;
        TreeNode* curr = new TreeNode(postorder[pi--]);

        int inind;
        for(int i=is;i<=ie;i++){
            if(inorder[i] == curr->val){
                inind = i;
                break;
            }
        }

        curr->right = func(inorder, postorder, inind+1, ie, pi);
        curr->left = func(inorder, postorder, is, inind-1,pi);

        return curr;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pi = postorder.size()-1;
        TreeNode* res = func(inorder, postorder, 0,inorder.size()-1,pi);
        return res;
    }
};