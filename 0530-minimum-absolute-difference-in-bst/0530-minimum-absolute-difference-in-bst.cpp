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
    void inorder(TreeNode* root, vector<int> &res){
        if(!root) return;
        
        res.push_back(root->val);
        inorder(root->left,res);
        inorder(root->right,res);
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        vector<int> res;
        inorder(root,res);
        sort(res.begin(),res.end());
        int n = res.size();
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            int diff = res[i]-res[i-1];
            ans = min(ans,diff);
        }
        return ans;
    }
};