class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                area = max(dfs(grid, row, col, 0), area);
            }
        }

        return area;
    }

    int dfs(vector<vector<int>>& grid, int row, int col, int area) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return 0;
        }
        if (grid[row][col] == 1) {
            area++;
            grid[row][col] = 0;
            area = max(dfs(grid, row + 1, col, area), area);
            area = max(dfs(grid, row - 1, col, area), area);
            area = max(dfs(grid, row, col + 1, area), area);
            area = max(dfs(grid, row, col - 1, area), area);
        }

        return area;
    }
};
