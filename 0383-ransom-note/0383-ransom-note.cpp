class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());

        if(n>m) return false;

        int j = 0, i = 0;
        while(i<m){
            if(magazine[i] == ransomNote[j]){
                i++; j++;
            }
            else{
                i++;
            }
        }
        if(j == n) return true;
        else return false;
    }
};