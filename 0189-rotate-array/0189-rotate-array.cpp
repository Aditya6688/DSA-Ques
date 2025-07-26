class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return;
        k = k % n;
        vector<int> v1,v2;
        for(int i=0;i<n-k;i++){
            v1.push_back(nums[i]);
        }
        for(int i=n-k;i<n;i++){
            v2.push_back(nums[i]);
        }
        int a = v1.size();
        int b = v2.size();
        for(int i=0;i<b;i++) nums[i] = v2[i];
        for(int i=0;i<a;i++) nums[i+b] = v1[i];
    }
};