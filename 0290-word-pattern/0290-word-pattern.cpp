class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int a = s.size();
        int b = pattern.size();

        vector<string> v;
        string res = "";
        for(int i=0;i<a;i++){
            if(s[i] == ' '){
                v.push_back(res);
                res.clear();
            }
            else{
                res+=s[i];
            }
        }
        v.push_back(res);

        if(b != v.size()) return false;

        unordered_map<char,string>m1;
        unordered_map<string,char>m2;

        for(int i=0;i<b;i++){
            if(m1.find(pattern[i]) == m1.end() && m2.find(v[i]) == m2.end()){
                m1[pattern[i]] = v[i];
                m2[v[i]] = pattern[i];
            }
            
            else{
                if(m1[pattern[i]] != v[i] || m2[v[i]] != pattern[i])
                return false;
            }
        }
        return true;
    }
};