class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> res = intervals[0];

        int n = intervals.size();
        if(n == 1) return intervals;

        for(int i=0;i<n;i++){
            if(intervals[i][0] <= res.back()){
                res.back() = max(res.back(),intervals[i][1]);
            }
            else{
                ans.push_back(res);
                res = intervals[i];
            }
        }

        ans.push_back(res);
        return ans;
    }
};