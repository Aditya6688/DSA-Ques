class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n == 1) return intervals;

        sort(intervals.begin(),intervals.end());
        vector<int> ans = intervals[0];

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ans.back()){
                ans.back() = max(ans.back(),intervals[i][1]);
            }
            else{
                res.push_back(ans);
                ans = intervals[i];
            }
        }
        res.push_back(ans);
        return res;
    }
};