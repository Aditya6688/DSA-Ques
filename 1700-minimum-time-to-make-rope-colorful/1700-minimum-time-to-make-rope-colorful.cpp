class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int sum = 0;
        int maxTime = neededTime[0];
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i-1]) {
                sum += min(neededTime[i], maxTime);
                maxTime = max(maxTime, neededTime[i]);
            } else {
                maxTime = neededTime[i];
            }
        }
        return sum;
    }
};