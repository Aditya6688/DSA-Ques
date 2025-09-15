class Solution {
public:
    void func(vector<vector<int>>& res, vector<int>& ans, int idx,
              vector<int>& nums) {
        if (idx == nums.size()) {
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[idx]);
        func(res, ans, idx + 1, nums);
        ans.pop_back();

        func(res, ans, idx + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;

        func(res, ans, 0, nums);
        return res;
    }
};