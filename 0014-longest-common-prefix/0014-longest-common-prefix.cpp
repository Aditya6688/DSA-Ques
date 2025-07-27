class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();
        string ans = "";

        for(int i = 0; i < first.size() && i < last.size(); i++) {
            if(first[i] == last[i])
                ans += first[i];
            else
                break;
        }
        return ans;
    }
};