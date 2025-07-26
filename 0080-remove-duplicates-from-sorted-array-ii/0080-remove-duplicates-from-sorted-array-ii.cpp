class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // Already satisfies the condition

        int k = 2; // Start from index 2 since the first two elements are always valid

        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
    }
};