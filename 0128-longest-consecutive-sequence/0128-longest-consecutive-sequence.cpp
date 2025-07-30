class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {  // iterate over set to avoid duplicates
            if (s.find(num - 1) == s.end()) {  // start of a new sequence
                int curr = 1;
                int currentNum = num;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    curr++;
                }

                longest = max(longest, curr);
            }
        }

        return longest;
    }
};