class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n == 1) return {0};

        for(int i=-n/2;i<=n/2;i++){
            if(n%2 == 0 && i == 0) continue;
            res.push_back(i);
        }

        return res;
    }
};