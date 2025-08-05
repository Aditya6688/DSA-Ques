class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[1] < b[1]; // sort by end coordinate
        });
        int n = points.size();
        int cnt = 1, x = points[0][1];

        for(int i=1;i<n;i++){
            if(points[i][0]<=x){
                continue;
            }
            else{
                x = points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};