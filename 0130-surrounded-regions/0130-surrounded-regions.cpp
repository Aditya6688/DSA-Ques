class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        
        board[i][j] = '#'; // mark as visited
        dfs(board, i + 1, j); // down
        dfs(board, i - 1, j); // up
        dfs(board, i, j + 1); // right
        dfs(board, i, j - 1); // left
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            dfs(board,i, 0);
            dfs(board,i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(board,0, j);
            dfs(board,m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};