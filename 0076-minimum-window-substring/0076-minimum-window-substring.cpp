class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0), window(128, 0);
        for (char c : t) need[c]++;

        int have = 0, required = 0;
        for (int c : need) if (c > 0) required++;

        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;

        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            if (need[c] > 0 && window[c] == need[c]) {
                have++;
            }

            while (have == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                char leftChar = s[l];
                window[leftChar]--;
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    have--;
                }
                l++;
            }
            r++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};