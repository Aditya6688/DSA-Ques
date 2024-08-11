class Solution {
public:
    bool isd(string s1, string s2){
        int n = s1.size(), m = s2.size();
        string s = s2;

        while(s1.size()>=s2.size()){
            if(s1 == s2) return true;
            s2+=s;
        }
        return false;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1 == str2) return str1;
        int i = 1;
        int n = str1.size();
        string res = "";
        while(i<=n){
            string a = str1.substr(0,i);
            if(isd(str1,a) and isd(str2,a)) res = a;
            i++;
        }
        return res;
    }
};