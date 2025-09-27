class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        int n = strs.size();

        for(int i=0;i<n;i++){
            string ans = strs[i];
            sort(ans.begin(),ans.end());

            mp[ans].push_back(strs[i]);
        }

        for(auto x:mp){
            res.push_back(x.second);
        }

        return res;
    }
};