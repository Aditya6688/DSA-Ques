class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int bp = prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<bp){
                bp = prices[i];
            }
            else{
                profit += (prices[i]-bp);
                bp = prices[i];
            }
        }
        return profit;
    }
};