class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        string final = "";
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] != ' '){
                ans+=s[i];
            }
            else{
                if(ans!=""){
                    res.push_back(ans);
                    ans.clear();
                }
            }
        }
        if(ans!="") res.push_back(ans);

        int m = res.size();
        for(int i=m-1;i>=0;i--){
            final += res[i];
            if(i != 0) final += ' ';
        }
        return final;
    }
};