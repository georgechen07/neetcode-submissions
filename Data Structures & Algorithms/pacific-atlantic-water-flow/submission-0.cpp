class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
        stack<pair<int, int>> dfs;

        for (int j = 0; j < heights[0].size(); ++j) {
            dfs.push(pair<int, int>{0, j});
        }
        for (int j = 1; j < heights.size(); ++j) {
            dfs.push(pair<int, int>{j, 0});
        }

        while (!dfs.empty()) {
            pair<int, int> curr = dfs.top();
            // cout << curr.first << " " << curr.second << '\n';
            dfs.pop();
            pacific.insert(curr);
            if (curr.first - 1 >= 0
                && heights[curr.first - 1][curr.second] >= heights[curr.first][curr.second]
                && !pacific.contains({curr.first - 1, curr.second})) {
                dfs.push({curr.first - 1, curr.second});
            }
            if (curr.first + 1 < heights.size()
                && heights[curr.first + 1][curr.second] >= heights[curr.first][curr.second]
                && !pacific.contains({curr.first + 1, curr.second})) {
                dfs.push({curr.first + 1, curr.second});
            }
            if (curr.second - 1 >= 0
                && heights[curr.first][curr.second - 1] >= heights[curr.first][curr.second]
                && !pacific.contains({curr.first, curr.second - 1})) {
                dfs.push({curr.first, curr.second - 1});
            }
            if (curr.second + 1 < heights[0].size()
                && heights[curr.first][curr.second + 1] >= heights[curr.first][curr.second]
                && !pacific.contains({curr.first, curr.second + 1})) {
                dfs.push({curr.first, curr.second + 1});
            }
        }

        for (int j = 0; j < heights[0].size(); ++j) {
            dfs.push(pair<int, int>{heights.size() - 1, j});
        }
        for (int j = 0; j < heights.size() - 1; ++j) {
            dfs.push(pair<int, int>{j, heights[0].size() - 1});
        }

        while (!dfs.empty()) {
            pair<int, int> curr = dfs.top();
            dfs.pop();
            atlantic.insert(curr);
            if (curr.first - 1 >= 0
                && heights[curr.first - 1][curr.second] >= heights[curr.first][curr.second]
                && !atlantic.contains({curr.first - 1, curr.second})) {
                dfs.push({curr.first - 1, curr.second});
            }
            if (curr.first + 1 < heights.size()
                && heights[curr.first + 1][curr.second] >= heights[curr.first][curr.second]
                && !atlantic.contains({curr.first + 1, curr.second})) {
                dfs.push({curr.first + 1, curr.second});
            }
            if (curr.second - 1 >= 0
                && heights[curr.first][curr.second - 1] >= heights[curr.first][curr.second]
                && !atlantic.contains({curr.first, curr.second - 1})) {
                dfs.push({curr.first, curr.second - 1});
            }
            if (curr.second + 1 < heights[0].size()
                && heights[curr.first][curr.second + 1] >= heights[curr.first][curr.second]
                && !atlantic.contains({curr.first, curr.second + 1})) {
                dfs.push({curr.first, curr.second + 1});
            }
        }
    
        vector<vector<int>> res;
        for (auto const& [row, col] : atlantic) {
            // cout << "[" << row << "," << col << "], "; 
            if (pacific.contains({row, col})) {
                res.push_back(vector<int>{row, col});
            }
        }
        // cout << '\n';

        return res;
    }
};
