class Solution {
public:
    void dfs(int l, int r, string s, int n, vector<string>& res){
        if(s.size() == n*2){
            res.push_back(s);
            return;
        }

        if(l<n) dfs(l+1,r,s+'(',n,res);
        if(r<l) dfs(l,r+1,s+')',n,res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0,0,"",n,res);
        return res;
    }
};