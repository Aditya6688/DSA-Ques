class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int res = 0;
        vector<int> v;
        v.push_back(0);
        v.push_back(gain[0]);

        for(int i=1;i<n;i++){
            int ans = gain[i]+v[i];
            res = max(res,ans);
            v.push_back(ans);
        }
        return *max_element(v.begin(),v.end());
    }
};