class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        
        v1[0] = nums[0];
        for(int i=1;i<n;i++){
            v1[i] = nums[i]*v1[i-1];
        }
        v2[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            v2[i] = nums[i]*v2[i+1];
        }

        nums[0] = v2[1];
        nums[n-1] = v1[n-2];
        for(int i=1;i<n-1;i++){
            nums[i] = v1[i-1]*v2[i+1];
        }
        return nums;
    }
};