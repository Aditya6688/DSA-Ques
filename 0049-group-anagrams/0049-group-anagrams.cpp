class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());  // sorted version is the key
            mp[t].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& [key, group] : mp) {
            res.push_back(group);
        }
        return res;
    }
};