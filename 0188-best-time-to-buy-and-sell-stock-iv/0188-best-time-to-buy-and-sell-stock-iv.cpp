class Solution {
public:
    int recurse(int i, int j, int k, int l, vector<int>& prices, map<vector<int>, int>& mem) {
        if (mem.count({i, j, l})) {
            // Memoization: solution is already calculated
            return mem[{i, j, l}];
        }
        if (i == prices.size()) {
            // No more stocks to buy/sell anyways
            return 0;
        }
        if (j == k) {
            // Already used up all transactions
            return 0;
        }
        int best;
        if (l == 0) {
            // Then either don't sell the stock or sell the stock
            best = max(recurse(i+1, j, k, l, prices, mem), recurse(i+1, j, k, 1, prices, mem) - prices[i]);
        }
        else {
            // Then either don't buy the stock or buy the stock
            best = max(recurse(i+1, j, k, l, prices, mem), recurse(i+1, j+1, k, 0, prices, mem) + prices[i]);
        }
        mem[{i, j, l}] = best; // Store to not need to recalculate
        return best;
    }
    int maxProfit(int k, vector<int>& prices) {
        map<vector<int>, int> mem;
        return recurse(0, 0, k, 0, prices, mem);
    }
};