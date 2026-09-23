class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> traversal;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    traversal.push({i, j});
                }
            }
        }        

        int level = 0;
        while (!traversal.empty()) {
            int starting = traversal.size();
            // cout << starting << ' ' << level << '\n';
            for (int k = 0; k < starting; ++k) {
                auto [row, col] = traversal.front();
                traversal.pop();
                // cout << row << " " << col << " " << level << '\n';
                grid[row][col] = min(level, grid[row][col]);
                if (row + 1 < grid.size() && grid[row + 1][col] == 2147483647) {
                    traversal.push({row + 1, col});
                    --grid[row + 1][col];
                }
                if (row - 1 >= 0 && grid[row - 1][col] == 2147483647) {
                    traversal.push({row - 1, col});
                    --grid[row - 1][col];
                }
                if (col + 1 < grid[0].size() && grid[row][col + 1] == 2147483647) {
                    traversal.push({row, col + 1});
                    --grid[row][col + 1];
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 2147483647) {
                    traversal.push({row, col - 1});
                    --grid[row][col - 1];
                }
            }
            ++level;
        }
    }
};
