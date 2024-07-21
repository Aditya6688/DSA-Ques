class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
    int count0 = 0, count1 = 0;

    // Count the number of '0's and '1's
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }

    // If the difference between the count of '0's and '1's is more than 1, return -1
    if (abs(count0 - count1) > 1) return -1;

    // Initialize the two possible alternating patterns
    string pattern1 = "", pattern2 = "";
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            pattern1 += '0';
            pattern2 += '1';
        } else {
            pattern1 += '1';
            pattern2 += '0';
        }
    }

    // Calculate the number of swaps needed to convert the string to each pattern
    int swaps1 = 0, swaps2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != pattern1[i]) swaps1++;
        if (s[i] != pattern2[i]) swaps2++;
    }

    // If the counts of '0's and '1's are equal, the answer is the minimum of the two swap counts
    if (count0 == count1) return min(swaps1, swaps2) / 2;

    // If the count of '0's is more, the answer is swaps1/2 (because pattern1 starts with '0')
    if (count0 > count1) return swaps1 / 2;

    // If the count of '1's is more, the answer is swaps2/2 (because pattern2 starts with '1')
    return swaps2 / 2;
    }
};