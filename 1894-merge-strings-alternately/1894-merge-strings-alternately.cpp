class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int n = word1.size();
        int m = word2.size();
        string res = "";

        while(i<n and j<m){
            res+=word1[i];
            res+=word2[j];
            i++; j++;
        }
        while(i<n){
            res+=word1[i];
            i++;
        }
        while(j<m){
            res+=word2[j];
            j++;
        }
        return res;
    }
};