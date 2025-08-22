class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;

        // dp[i][j] = true if s3[0...(i+j-1)] can be formed
        // by interleaving s1[0...(i-1)] and s2[0...(j-1)]
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true; // empty + empty = empty

        // Fill first row (only using s2)
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        // Fill first column (only using s1)
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1])   // take from s1
                        || (dp[i][j-1] && s2[j-1] == s3[i+j-1]); // take from s2
            }
        }

        return dp[m][n];
    }
};