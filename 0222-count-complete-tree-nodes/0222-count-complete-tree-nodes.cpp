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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* curr = root;
        int lc = 0, rc = 0;
        while(curr){
            lc++;
            curr = curr->left;
        }

        curr = root;
        while(curr){
            rc++;
            curr = curr->right;
        }

        if(lc == rc) return pow(2,lc)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};