class Solution {
public:
    string reverseVowels(string s) {
        if(s == " ") return s;
        int n = s.size();
        vector<char>v;
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U')
            v.push_back(s[i]);
        }
        int m = v.size();
        if(m == 0) return s;
        int i=m-1,j=0;
        for(int k=0;k<n;k++){
            if(s[k] == v[j]){
                s[k] = v[i];
                i--; j++;
            }
            if(i<0 || j>m-1) break;
        }
        return s;
    }
};