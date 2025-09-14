class Solution {
public:
    int func(int n) {
        int cnt = 0;
        while(n){
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int>v;
        for(int i=0;i<=n;i++){
            int x = func(i);
            v.push_back(x);
        }
        return v;
    }
};