class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0;
        int sum = 0;
        int res = INT_MAX;

        while(i<n){
            sum+=nums[i];
            while(sum>=target){
                res = min(res,i-j+1);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        return res == INT_MAX ? 0 : res;
    }
};