class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        vector<int> v;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi,matrix[j][i]);
            }
            v.push_back(maxi);
            maxi = 0;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = v[j];
                }
            }
        }
        return matrix;
    }
};