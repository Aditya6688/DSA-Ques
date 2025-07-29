class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0) v.push_back({i,j});
            }
        }

        for(const auto &p:v){
            for(int j=0;j<m;j++){
                matrix[p.first][j] = 0;
            }
            for(int i=0;i<n;i++){
                matrix[i][p.second] = 0;
            }
        }
    }
};