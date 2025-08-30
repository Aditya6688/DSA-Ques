class Solution {
public:
    string convert(string s, int numRows) {
        map<int,string> mp;
        if (numRows == 1) return s;
        int n = s.size();
        int a = 0;
        bool st = true;

        for(int i=0;i<n;i++){
            mp[a]+=s[i];
            if(st == true) a++;
            else a--;

            if(a == 0 || a == numRows-1) st = !st;
        }

        string res = "";
        for(auto &x:mp){
            res+=x.second;
        }
        return res;
    }
};