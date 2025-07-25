class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int>v;
        for(int i=0; i<n;i++){
            if(nums[i] != val) v.push_back(nums[i]);
        }

        int m = v.size();
        for(int i=0;i<m;i++){
            nums[i] = v[i];
        }
        return m;
    }
};