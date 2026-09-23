class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;
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
            for (int i = 0; i < starting; ++i) {
                auto [row, col] = traversal.front();
                traversal.pop();
                if (row < 0 || row >= grid.size() || col < 0
                    || col >= grid[0].size() || grid[row][col] == -1 || visited.contains({row, col})
                ) {
                    continue;
                }
                grid[row][col] = level;
                visited.insert({row, col});
                traversal.push({row + 1, col});
                traversal.push({row - 1, col});
                traversal.push({row, col + 1});
                traversal.push({row, col - 1});
            }
            ++level;
        }
    }
};
