class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size(),cnt = 0;
        for(int i=0;i<n;i++){
            string s = details[i];
            int a = (s[11] - '0')*10;
            int b = s[12] - '0';
            int ans = a+b;
            if(ans > 60) cnt++;
        }
        return cnt;
    }
};