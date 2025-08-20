class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                ans = m;       // possible first occurrence
                e = m - 1;     // go left
            }
            else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                ans = m;       // possible last occurrence
                s = m + 1;     // go right
            }
            else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};