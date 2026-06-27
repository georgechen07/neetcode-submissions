class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto squares = vector<vector<bool>>(9, vector<bool>(9, false));
        auto rows = vector<vector<bool>>(9, vector<bool>(9, false));
        auto cols = vector<vector<bool>>(9, vector<bool>(9, false));

        // for (int a = 0; a < 9; a++) {
        //     cout << "square number " << a << "\n";
        //     for (int b = 0; b < 9; b++) {
        //         cout << squares[a][b] << '\n';
        //     }
        //     cout << "row number " << a << "\n";
        //     for (int b = 0; b < 9; b++) {
        //         cout << rows[a][b] << '\n';
        //     }
        // }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (rows[i][board[i][j] - '0' - 1] ||
                    cols[j][board[i][j] - '0' - 1] ||
                    squares[3 * (i / 3) + j / 3][board[i][j] - '0' - 1]) {
                    cout << "i = " << i << " j = " << j << '\n';
                    cout << rows[i][board[i][j] - '0' - 1] << '\n';
                    cout << cols[j][board[i][j] - '0' - 1] << '\n';
                    cout << squares[i / 3 + j / 3][board[i][j] - '0' - 1] << '\n';
                    return false;
                } else {
                    rows[i][board[i][j] - '0' - 1] = true;
                    cols[j][board[i][j] - '0' - 1] = true;
                    squares[i / 3 + j / 3][board[i][j] - '0' - 1] = true;
                }
            }
        }

        return true;
    }
};
