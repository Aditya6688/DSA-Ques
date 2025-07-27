class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z') res+=(tolower(s[i]));
            else if(s[i]>='a' && s[i]<='z') res+=s[i];
            else if(s[i]>='0' && s[i]<='9') res+=s[i];
        }

        string s1 = res;
        reverse(s1.begin(), s1.end());
        return (res == s1);
    }
};