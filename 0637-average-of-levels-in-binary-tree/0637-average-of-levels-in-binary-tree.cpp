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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum = 0, avg = 0;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                sum+=curr->val;
                avg = sum/n;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(avg);
        }
        return res;
    }
};