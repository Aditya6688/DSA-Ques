class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        // Directions for the 8 neighbors
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // Step 1: Use in-place encoding
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;

                for (auto& dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;

                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        // Original value is either 1 (live) or -1 (was 1, now dead)
                        if (abs(board[x][y]) == 1) {
                            ++liveNeighbors;
                        }
                    }
                }

                // Apply rules:
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1;  // Live to dead
                } else if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2;   // Dead to live
                }
            }
        }

        // Step 2: Finalize update
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};