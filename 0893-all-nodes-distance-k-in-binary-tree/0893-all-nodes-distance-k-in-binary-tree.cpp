/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> graph;

    void buildGraph(TreeNode* node, TreeNode* parent) {
        if (!node) return;

        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr);

        queue<int> q;
        unordered_set<int> visited;
        q.push(target->val);
        visited.insert(target->val);
        
        int currentDistance = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentDistance == k) break;
            currentDistance++;

            for (int i = 0; i < size; ++i) {
                int currentNode = q.front();
                q.pop();

                for (int neighbor : graph[currentNode]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};