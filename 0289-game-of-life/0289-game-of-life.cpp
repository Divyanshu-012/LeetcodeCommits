class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> newX = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> newY = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + newX[k];
                    int y = j + newY[k];
                    if (x >= 0 && y >= 0 && x < n && y < m &&
                        (board[x][y] == 1 || board[x][y] == 3)) {
                        count++;
                    }
                }

                if (board[i][j] == 1 && (count < 2 || count > 3)) {
                    board[i][j] = 3; // alive to dead
                } else if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 4; // dead to alive
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 3) board[i][j] = 0;
                else if (board[i][j] == 4) board[i][j] = 1;
            }
        }
    }
};