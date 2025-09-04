class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0,res=  INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            res = max(res,sum);
            if(sum<0) sum = 0;
        }
        if(res!=INT_MIN)
        return res;
        else
        return -1;
    }
};