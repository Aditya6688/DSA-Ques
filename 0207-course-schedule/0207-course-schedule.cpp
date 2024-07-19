class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create the adjacency list representation of the graph
        unordered_map<int, vector<int>> adjList;
        for (auto& pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
        }

        // Track visited nodes to avoid revisiting them
        vector<int> visited(numCourses, 0); // 0: not visited, 1: visiting, 2: visited

        // DFS function to detect a cycle
        function<bool(int)> dfs = [&](int node) {
            if (visited[node] == 1) return true; // found a cycle
            if (visited[node] == 2) return false; // already processed, no cycle

            visited[node] = 1; // mark as visiting
            for (int neighbor : adjList[node]) {
                if (dfs(neighbor)) return true;
            }
            visited[node] = 2; // mark as visited
            return false;
        };

        // Check for cycles in the graph
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i)) return false;
        }
        return true;
    }
};