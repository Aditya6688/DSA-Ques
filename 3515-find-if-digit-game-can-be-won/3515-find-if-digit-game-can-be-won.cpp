class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, sum1 = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]<10) sum1+= nums[i];
        }
        int sum2= sum-sum1;
        if(sum1 == sum2) return false;
        else
        return true;
    }
};