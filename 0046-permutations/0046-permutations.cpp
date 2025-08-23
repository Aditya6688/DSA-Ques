class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;

    void func(vector<int>& nums, int idx){
        if (nums.size() == idx) {
            res.push_back(ans);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            ans = nums;
            func(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        func(nums,0);
        return res;
    }
};