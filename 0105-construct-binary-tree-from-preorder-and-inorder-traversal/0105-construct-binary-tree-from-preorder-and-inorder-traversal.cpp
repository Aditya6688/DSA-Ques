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
    int prei = 0;
    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int is, int ie){
        if(is>ie) return nullptr;

        TreeNode* curr = new TreeNode(preorder[prei++]);
        int inidx = 0;

        for(int i=is;i<=ie;i++){
            if(inorder[i] == curr->val){
                inidx = i;
                break;
            }
        }

        curr->left = func(preorder,inorder,is,inidx-1);
        curr->right = func(preorder,inorder,inidx+1,ie);

        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size()-1;
        return func(preorder,inorder,0,n);
    }
};