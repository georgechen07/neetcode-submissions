class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        recurse(matrix, 0, matrix.size() - 1);
    }

    void recurse(vector<vector<int>>& matrix, int start, int end) {
        if (end <= start) {
            return;
        }
        for (int counter = start; counter < end; counter++) {
            int temp = matrix[start][start];
            int i = start;
            int j = start;

            while (i < end) {
                matrix[i][j] = matrix[i + 1][j];
                i++;
            }
            while (j < end) {
                matrix[i][j] = matrix[i][j + 1];
                j++;
            }
            while (i > start) {
                matrix[i][j] = matrix[i - 1][j];
                i--;
            }
            while (j > start + 1) {
                matrix[i][j] = matrix[i][j - 1];
                j--;
            }
            matrix[i][j] = temp;
        }
        recurse(matrix, start + 1, end - 1);
    }
};
