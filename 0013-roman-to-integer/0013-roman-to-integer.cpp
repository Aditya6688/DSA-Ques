class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10;
        mp['L'] = 50; mp['C'] = 100; mp['D'] = 500; mp['M'] = 1000;
        // mp['IV'] = 4; mp['IX'] = 9; mp['XL'] = 50; mp['XC'] = 90;
        // mp['CD'] = 500; mp['CM'] = 900;

        int n = s.size();
        int res = 0;
        for(int i=0;i<n;i++){
            if(i>0 and mp[s[i]] > mp[s[i-1]]){
                res+=mp[s[i]];
                res-=(2*mp[s[i-1]]);
            }
            else{
                res+=mp[s[i]];
            }
        }
        return res;
    }
};