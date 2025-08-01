class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int count=0;
        int m = matrix.size();
        int n = matrix[0].size();
        int total_ele=m*n;

        int top = 0, bottom = m-1;
        int left = 0, right = n-1;

        while(count < total_ele){
            for(int i = left; i<= right && count<total_ele; i++){
                res.push_back(matrix[top][i]); count++;
            }
            top++;
            for(int i = top; i<= bottom && count<total_ele; i++){
                res.push_back(matrix[i][right]); count++;
            }
            right--;
            for(int i = right; i>= left && count<total_ele; i--){
                res.push_back(matrix[bottom][i]); count++;
            }
            bottom--;
            for(int i = bottom; i>= top && count<total_ele; i--){
                res.push_back(matrix[i][left]); count++;
            }
            left++;
        }
        return res;
    }
};