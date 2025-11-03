class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0,res = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                cnt++;
                res = max(res,cnt);
            }
            else{
                cnt = 0;
            }
        }
        return res;
    }
};