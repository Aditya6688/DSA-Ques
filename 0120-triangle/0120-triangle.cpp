class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // dp starts as the last row of the triangle
        vector<int> dp = triangle[n-1];

        // process from second last row up to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0]; // result at the top
    }
};