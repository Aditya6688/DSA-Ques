class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber){
            columnNumber--;
            int r = columnNumber%26;
            res = res + char('A'+r);
            columnNumber = columnNumber/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};