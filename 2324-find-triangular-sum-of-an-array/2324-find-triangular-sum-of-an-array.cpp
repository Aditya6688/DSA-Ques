class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int a = n-1;

        while(a){
            vector<int> v(a);
            for(int i=0;i<a;i++){
                v[i] = (nums[i]+nums[i+1])%10;
            }
            nums = v;
            a--;
        }
        return nums[0];
    }
};