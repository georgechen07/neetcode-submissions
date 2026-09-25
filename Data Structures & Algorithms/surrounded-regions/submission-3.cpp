class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> bfs;
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = '0';
                bfs.push({0, i});
            }
            if (board[board.size() - 1][i] == 'O') {
                board[board.size() - 1][i] = '0';
                bfs.push({board.size() - 1, i});
            }
        }

        for (int i = 1; i < board.size() - 1; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '0';
                bfs.push({i, 0});
            }
            if (board[i][board[0].size() - 1] == 'O') {
                board[i][board[0].size() - 1] = '0';
                bfs.push({i, board[0].size() - 1});
            }
        }

        while (!bfs.empty()) {
            auto [row, col] = bfs.front();
            bfs.pop();
            if (row - 1 >= 0 && board[row - 1][col] == 'O') {
                board[row - 1][col] = '0';
                bfs.push({row - 1, col});
            }
            if (row + 1 < board.size() && board[row + 1][col] == 'O') {
                board[row + 1][col] = '0';
                bfs.push({row + 1, col});
            }
            if (col - 1 >= 0 && board[row][col - 1] == 'O') {
                board[row][col - 1] = '0';
                bfs.push({row, col - 1});
            }
            if (col + 1 < board[0].size() && board[row][col + 1] == 'O') {
                board[row][col + 1] = '0';
                bfs.push({row, col + 1});
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '0') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
