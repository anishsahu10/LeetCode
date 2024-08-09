class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check boundaries and if the current cell is water or already visited
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';
        
        // Perform DFS in all four possible directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int numIslands = 0;
        
        // Traverse through each cell in the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // If the current cell is land, start a DFS to mark the whole island
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numIslands;
    }
};