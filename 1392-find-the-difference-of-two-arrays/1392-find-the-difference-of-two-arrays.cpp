class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> res(2);
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());

    // Find elements in nums1 that are not in nums2
    for (int num : s1) {
        if (s2.find(num) == s2.end()) {
            res[0].push_back(num);
        }
    }

    // Find elements in nums2 that are not in nums1
    for (int num : s2) {
        if (s1.find(num) == s1.end()) {
            res[1].push_back(num);
        }
    }

    return res;
    }
};