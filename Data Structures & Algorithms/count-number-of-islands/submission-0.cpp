class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                count += dfs(grid, row, col);
            }
        }

        return count;
    }

    int dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return 0;
        }
        if (grid[row][col] == '1') {
            grid[row][col] = '0';
            dfs(grid, row + 1, col);
            dfs(grid, row - 1, col);
            dfs(grid, row, col + 1);
            dfs(grid, row, col - 1);

            return 1;
        }

        return 0;
    }
};
