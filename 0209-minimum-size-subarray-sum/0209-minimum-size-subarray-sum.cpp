class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, res = INT_MAX, sum = 0, j = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cnt++;
            while(sum>=target){
                sum-=nums[j];
                j++;
                res = min(res,cnt);
                cnt--;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};