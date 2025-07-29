class Solution {
public:
    bool row(vector<vector<char>>& b, int target, int a){
        int n = b.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(b[i][a] == target) cnt++;
        }

        return (cnt == 1);
    }

    bool col(vector<vector<char>>& b, int target, int x){
        int m = b[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++){
            if(b[x][i] == target) cnt++;
        }

        return (cnt == 1);
    }

    bool box(vector<vector<char>>& b, int target, int qr, int qc){
        int cnt = 0;
        for(int i=qr;i<qr+3;i++){
            for(int j=qc;j<qc+3;j++){
                if(b[i][j] == target) cnt++;
            }
        }

        return (cnt == 1);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        bool res = true;

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] >='0' and board[i][j]<='9'){
                    if(!(row(board, board[i][j], j) &&
                         col(board, board[i][j], i) &&
                         box(board, board[i][j], (i / 3) * 3, (j / 3) * 3))){
                        return false;
                    }
                }
                // if(res == false) break;
            }
        }
        return true;
    }
};