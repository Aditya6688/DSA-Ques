class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        string res = "";
        string st = "";
        vector<string> v,v1;
        while(i<n){
            if(s[i] == ' ' and st.size()>0){
                v.push_back(st);
                st.clear();
            }
            else if(s[i] != ' '){
                st+=s[i];
            }
            i++;
        }
        if(st.size()>0) v.push_back(st);

        int m = v.size();
        for(int i=m-1;i>=0;i--){
            v1.push_back(v[i]);
        }
        int j = 0;
        while(j<m){
            res+=v1[j];
            if(j<m-1)
            res+=" ";
            j++;
        }
        return res;
    }
};