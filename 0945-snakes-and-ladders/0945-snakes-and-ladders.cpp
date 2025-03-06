class Solution {
public:
    int n;

   
    pair<int, int> getCoordinate(int step) {
        int row = n - 1 - (step - 1) / n;
        int col = (step - 1) % n;


        if ((row % 2 == 0 && n % 2 == 0) || (row % 2 != 0 && n % 2 != 0)) {
            col = n - 1 - col;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> q;
        
        
        q.push(1);
        visited[n - 1][0] = true;
        
        while (!q.empty()) {
            int N = q.size();
            
            while (N--) {
                int currPosition = q.front();
                q.pop();

                
                if (currPosition == n * n) return steps;

                
                for (int k = 1; k <= 6; k++) {
                    int nextPosition = currPosition + k;
                    
                    if (nextPosition > n * n) break;

                    auto [r, c] = getCoordinate(nextPosition);

                    
                    if (visited[r][c]) continue;
                    visited[r][c] = true;

                    
                    if (board[r][c] == -1) {
                        q.push(nextPosition);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }

        // If we exhaust all possibilities and never reach the last cell, return -1
        return -1;
    }
};