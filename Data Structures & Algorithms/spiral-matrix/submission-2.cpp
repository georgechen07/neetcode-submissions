class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return {};
        }

        recurse(matrix, 0, matrix[0].size(), matrix.size(), res);

        return res;
    }

    void recurse(vector<vector<int>>& matrix, int start, int end_x, int end_y, vector<int>& res) {
        if (end_x <= start || end_y <= start) {
            return;
        }
        for (int i = start; i < end_x; i++) {
            cout << "loop 1 " << matrix[start][i] << '\n';
            res.push_back(matrix[start][i]);
        }
        if (start == end_y - 1) {
            return;
        }
        for (int i = start + 1; i < end_y; i++) {
            cout << "loop 2 " << matrix[i][end_x - 1] << '\n';
            res.push_back(matrix[i][end_x - 1]);
        }
        if (start == end_x - 1) {
            return;
        }
        for (int i = end_x - 2; i >= start; i--) {
            cout << "loop 3 " << matrix[end_y - 1][i] << '\n';
            res.push_back(matrix[end_y - 1][i]);
        }
        for (int i = end_y - 2; i > start; i--) {
            cout << "loop 4 " << matrix[i][start] << '\n';
            res.push_back(matrix[i][start]);
        }
        recurse(matrix, start + 1, end_x - 1, end_y - 1, res);
    }
};
