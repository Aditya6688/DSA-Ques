class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> vis(256, false);
        int ans = 0;
        int n = s.size();
        string res = "";
        for(int i=0;i<n;i++){
            if(vis[s[i]] == false){
                res+=s[i];
                vis[s[i]] = true;
            }
            else{
                while(res.find(s[i]) != string::npos){
                    res.erase(0, 1);
                }
                res+=s[i];
            }
            int m = res.size();
            ans = max(ans,m);
        }
        return ans;
    }
};