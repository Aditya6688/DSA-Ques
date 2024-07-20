class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(const string& start, const string& end, unordered_set<string>& visited) {
        if (graph[start].find(end) != graph[start].end()) {
            return graph[start][end];
        }
        
        visited.insert(start);
        for (const auto& neighbor : graph[start]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double result = dfs(neighbor.first, end, visited);
                if (result != -1.0) {
                    return result * neighbor.second;
                }
            }
        }
        
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph.clear();
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        
        vector<double> results;
        for (const auto& query : queries) {
            if (graph.find(query[0]) == graph.end() || graph.find(query[1]) == graph.end()) {
                results.push_back(-1.0);
            } else if (query[0] == query[1]) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(query[0], query[1], visited));
            }
        }
        
        return results;
    }
};