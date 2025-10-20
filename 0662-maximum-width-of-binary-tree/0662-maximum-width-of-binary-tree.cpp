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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long res = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            long long minIndex = q.front().second;  // leftmost index
            long long first = 0, last = 0;

            for (int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();

                // normalize index to prevent overflow
                long long curIndex = idx - minIndex;

                if (i == 0) first = curIndex;
                if (i == n - 1) last = curIndex;

                if (node->left)
                    q.push({node->left, 2 * curIndex});
                if (node->right)
                    q.push({node->right, 2 * curIndex + 1});
            }
            res = max(res, last - first + 1);
        }

        return (int)res;
    }
};