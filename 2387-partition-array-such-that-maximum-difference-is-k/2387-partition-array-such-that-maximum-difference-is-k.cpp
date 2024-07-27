class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt = 1, f = nums[0];
        int n = nums.size();
        if(n == 1) return 1;
        for(int i=1;i<n;i++){
            if(nums[i]-f > k){
                cnt++;
                f = nums[i];
            }
        }
        return cnt;
    }
};