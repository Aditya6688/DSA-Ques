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
        if (is > ie) return nullptr;

        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[pi++]);
        
        int si = 0;

        for(int i=is;i<=ie;i++){
            if(inorder[i] == root->val){
                si = i;
                break;
            }
        }

        root->left = func(preorder,inorder, is, si-1);
        root->right = func(preorder,inorder, si+1, ie);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return func(preorder,inorder,0,n-1);
    }
};