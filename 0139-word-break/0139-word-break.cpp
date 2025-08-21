class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // for O(1) lookup
        
        vector<bool> dp(n+1, false);
        dp[0] = true; // empty string can always be segmented
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break; // no need to check further for this i
                }
            }
        }
        return dp[n];
    }
};