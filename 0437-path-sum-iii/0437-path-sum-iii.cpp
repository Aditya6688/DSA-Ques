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
// Helper function to count paths using DFS
    int countPaths(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if (!node) return 0; // Base case: if the node is null, return 0

        // Update the current sum by adding the current node's value
        currentSum += node->val;

        // Check if there's a prefix sum that matches the target
        int pathCount = 0;
        if (prefixSums.find(currentSum - targetSum) != prefixSums.end()) {
            pathCount += prefixSums[currentSum - targetSum];
        }

        // Add the current sum to the prefix sums map
        prefixSums[currentSum]++;

        // Recurse on left and right subtrees
        pathCount += countPaths(node->left, currentSum, targetSum, prefixSums);
        pathCount += countPaths(node->right, currentSum, targetSum, prefixSums);

        // Backtrack: Remove the current sum from the map before going back up the recursive call stack
        prefixSums[currentSum]--;

        return pathCount;
    }

    int pathSum(TreeNode* root, int targetSum) {
        // Map to store the prefix sums and their counts
        unordered_map<long long, int> prefixSums;
        prefixSums[0] = 1; // Base case: There's one way to get a sum of 0

        // Call the helper function to count paths
        return countPaths(root, 0, targetSum, prefixSums);
    }
};