// \U0001f680 Course Schedule II using BFS Topological Sort (Kahn's Algorithm)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // \U0001f4cc Step 1: Build graph & indegree
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }
        
        // \U0001f4cc Step 2: Queue initialization
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        // \U0001f4cc Step 3: BFS processing
        vector<int> order;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            order.push_back(curr);
            
            for (int neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        
        // \U0001f4cc Step 4: Return result or empty array
        if (order.size() == numCourses) return order;
        return {};
    }
};