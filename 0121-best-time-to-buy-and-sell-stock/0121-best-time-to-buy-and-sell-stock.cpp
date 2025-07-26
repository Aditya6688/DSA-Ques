class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v1, v2;
        int n = prices.size();
        int res = 0;
        int a = prices[0];
        int b = prices[n-1];
        v1.push_back(a);
        v2.push_back(b);
        for(int i=1;i<n;i++){
            if(prices[i] < a){
                v1.push_back(prices[i]);
                a = prices[i];
            } 
            else v1.push_back(a); 
        }

        for(int i=n-2;i>=0;i--){
            if(prices[i]>b){
                v2.push_back(prices[i]);
                b = prices[i];
            }
            else v2.push_back(b);
        }
        reverse(v2.begin(),v2.end());

        for(int i=0;i<n;i++){
            res = max(res,(v2[i]-v1[i]));
        }
        return res;
    }
};