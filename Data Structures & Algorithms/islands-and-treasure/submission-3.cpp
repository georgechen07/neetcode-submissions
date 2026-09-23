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

        int starting = traversal.size();
        for (int k = 0; k < starting; ++k) {
            auto [row, col] = traversal.front();
            traversal.pop();
            traversal.push({row + 1, col});
            traversal.push({row - 1, col});
            traversal.push({row, col + 1});
            traversal.push({row, col - 1});
        }

        int level = 1;
        while (!traversal.empty()) {
            int starting = traversal.size();
            for (int i = 0; i < starting; ++i) {
                auto [row, col] = traversal.front();
                traversal.pop();
                if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()
                    || grid[row][col] == -1 || (grid[row][col] != 2147483647)
                ) {
                    continue;
                }
                grid[row][col] = level;

                traversal.push({row + 1, col});
                traversal.push({row - 1, col});
                traversal.push({row, col + 1});
                traversal.push({row, col - 1});
            }
            ++level;
        }
    }
};
