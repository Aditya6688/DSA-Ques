class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows, col;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    col.push_back(j);
                }
            }
        }

        int x = 0, y = 0;
        while(x<col.size()){
            for(int i=0;i<n;i++){
                matrix[i][col[x]] = 0;
            }
            x++;
        }
        while(y<rows.size()){
            for(int i=0;i<m;i++){
                matrix[rows[y]][i] = 0;
            }
            y++;
        }
    }
};