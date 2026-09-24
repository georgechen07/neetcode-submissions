class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> s;
        int fruit = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    s.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++fruit;
                }
            }
        }

        int minutes = 0;
        while (fruit > 0) {
            int starting = s.size();
            ++minutes;
            if (starting == 0) {
                return -1;
            }
            // cout << fruit << '\n';
            for (int f = 0; f < starting; ++f) {
                auto [row, col] = s.front();
                s.pop();
                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    --fruit;
                    grid[row - 1][col] = 2;
                    s.push({row - 1, col});
                }
                if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
                    --fruit;
                    grid[row + 1][col] = 2;
                    s.push({row + 1, col});
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    --fruit;
                    grid[row][col - 1] = 2;
                    s.push({row, col - 1});
                }
                if (col + 1 < grid[0].size() && grid[row][col + 1] == 1) {
                    --fruit;
                    grid[row][col + 1] = 2;
                    s.push({row, col + 1});
                }
            }
        }

        return minutes;
    }
};
