class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int s = 0, e = n-1;
        int res = 0;

        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]>=nums[s]){
                res = nums[s];
                ans = min(ans,res);
                s = m+1;
            }
            else{
                res = nums[m];
                ans = min(ans,res);
                e = m-1;
            }
        }
        return ans;
    }
};