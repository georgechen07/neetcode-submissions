class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool helper(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index == word.size()) {
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }

        if (board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '?';

        bool res = false;
        if (helper(board, word, row + 1, col, index + 1)
            || helper(board, word, row - 1, col, index + 1)
            || helper(board, word, row, col + 1, index + 1)
            || helper(board, word, row, col - 1, index + 1)) {
                res = true;
            }
        board[row][col] = temp;
        return res;
    }
};
