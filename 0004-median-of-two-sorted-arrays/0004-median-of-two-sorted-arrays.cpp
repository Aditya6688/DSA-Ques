class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for efficiency
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // swap arrays
        }
        int m = nums1.size(); // size of nums1
        int n = nums2.size(); // size of nums2

        int left = 0, right = m; // binary search range
        while (left <= right) {
            int i = (left + right) / 2; // partition nums1
            int j = (m + n + 1) / 2 - i; // partition nums2

            // Handle out-of-bounds by using INT_MIN/INT_MAX
            int nums1Left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1Right = (i == m) ? INT_MAX : nums1[i];
            int nums2Left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2Right = (j == n) ? INT_MAX : nums2[j];

            // Check if partition is correct
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                // Odd total length: median is max of left side
                if ((m + n) % 2 == 1) {
                    return double(max(nums1Left, nums2Left));
                } else {
                    // Even total length: median is average of max left and min right
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
            } else if (nums1Left > nums2Right) {
                // Move partition left
                right = i - 1;
            } else {
                // Move partition right
                left = i + 1;
            }
        }
        // Should never reach here if input is valid
        return 0.0;
    }
};