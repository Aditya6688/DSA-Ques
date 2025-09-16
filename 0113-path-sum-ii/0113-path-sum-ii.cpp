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
    void func(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& ans) {
        if (!root) return;

        ans.push_back(root->val); // include current node

        // If it's a leaf and the sum matches
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(ans);
        } else {
            // Recurse on children
            func(root->left, targetSum - root->val, res, ans);
            func(root->right, targetSum - root->val, res, ans);
        }

        ans.pop_back(); // backtrack
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;

        func(root,targetSum,res,ans);
        return res;
    }
};