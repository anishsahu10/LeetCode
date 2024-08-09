class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        // Check boundaries and if the cell is already 'X' or marked '*'
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        
        // Mark the current cell as visited by changing 'O' to '*'
        board[i][j] = '*';
        
        // Perform DFS in all four possible directions
        dfs(board, i + 1, j); // down
        dfs(board, i - 1, j); // up
        dfs(board, i, j + 1); // right
        dfs(board, i, j - 1); // left
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        // Step 1: Mark all 'O's on the border and their connected 'O's with '*'
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);        // Left border
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1); // Right border
        }
        
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);        // Top border
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j); // Bottom border
        }
        
        // Step 2: Flip all remaining 'O's to 'X's, as they are surrounded
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
        // Step 3: Convert all '*' back to 'O's to restore the border-connected regions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};