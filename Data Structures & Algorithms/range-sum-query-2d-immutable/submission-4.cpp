class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum_matrix = vector<vector<int>>(matrix.size(), vector<int>());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int sum = matrix[i][j];
                if (j != 0) {
                    sum += sum_matrix[i][j - 1];
                }
                if (i != 0) {
                    sum += sum_matrix[i - 1][j];
                    if (j != 0) {
                        sum -= sum_matrix[i - 1][j - 1];
                    }
                }
                // cerr << i << " " << j << " " << sum << endl;
                sum_matrix[i].push_back(sum);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sum_matrix[row2][col2];
        if (col1 > 0) {
            sum -= sum_matrix[row2][col1 - 1];
        }
        if (row1 > 0) {
            sum -= sum_matrix[row1 - 1][col2];
        }
        if (col1 * row1 != 0) {
            sum += sum_matrix[row1 - 1][col1 - 1];
        }
        return sum;
    }

private:
    vector<vector<int>> sum_matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */