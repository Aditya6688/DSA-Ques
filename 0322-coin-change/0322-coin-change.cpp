class Solution {
public:
    int func(vector<int>& coins, int amount, vector<vector<int>> &dp, int ind){
        int n = coins.size();

        if (amount == 0) return 0;
        if (ind == n) return 1e9; // no coins left

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = 1e9;
        if (coins[ind] <= amount)
            take = 1 + func(coins, amount - coins[ind], dp, ind);

        int notTake = func(coins, amount, dp, ind + 1);

        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(coins, amount, dp, 0);
        return (ans >= 1e9) ? -1 : ans;
    }
};