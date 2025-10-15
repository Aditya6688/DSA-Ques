class Solution {
public:
    int solve(int i, int j, vector<int>& points, vector<vector<int>>& memo) {
        // Base case
        if (j <= i + 1) {
            return 0;
        }

        // Check if we have already computed the result for this subproblem
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int min_cost = INT_MAX;
        int segment_length = points[j] - points[i];

        for (int k = i + 1; k < j; ++k) {
            int current_cost = segment_length + solve(i, k, points, memo) + solve(k, j, points, memo);
            min_cost = min(min_cost, current_cost);
        }

        // Store the result in the memo before returning
        return memo[i][j] = min_cost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> memo(m,vector<int>(m, -1));

        return solve(0, m - 1, cuts, memo);
    }
};