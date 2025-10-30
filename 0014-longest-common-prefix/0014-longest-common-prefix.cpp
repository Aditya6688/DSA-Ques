class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int i = 0;
        string res = "";
        sort(strs.begin(),strs.end());

        while(i < min(strs[0].size(), strs[n-1].size())) {
            if(strs[0][i] == strs[n-1][i]) res+=strs[0][i];
            else break;
            i++;
        }
        return res;
    }
};