class Solution {
public:
    int uniquePaths(int m, int n) {
        auto pathCount = vector<vector<int>>(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                --pathCount[i][j];
                pathCount[i][j] += pathCount[i - 1][j];
                pathCount[i][j] += pathCount[i][j - 1];
            }
        }

        return pathCount[m - 1][n - 1];
    }
};
