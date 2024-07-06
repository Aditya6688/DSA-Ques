class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "")
        return true;

        int i=0,j=0;
        while(i<t.size()){
            if(j == s.size()-1 and s[j] == t[i])
            return true;

            if(s[j] == t[i]){
                j++;
                i++;
            }
            else
            i++;
        }
        return false;
    }
};