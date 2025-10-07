class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> mp(256, false);
        int left = 0, right = 0, ans = 0;
        int n = s.size();

        while (right < n) {
            if (mp[s[right]] == false) {
                mp[s[right]] = true;
                ans = max(ans, right - left + 1);
                right++;
            } else {
                mp[s[left]] = false; // unmark the leftmost char
                left++;
            }
        }

        return ans;
    }
};