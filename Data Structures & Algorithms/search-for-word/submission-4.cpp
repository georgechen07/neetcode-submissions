class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                set<pair<int, int>> visited;
                if (helper(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int row, int col, int index, set<pair<int, int>> visited) {
        if (index == word.size()) {
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited.contains(pair{row, col})) {
            return false;
        }

        if (board[row][col] != word[index]) {
            return false;
        }

        visited.insert(pair{row, col});

        bool res = false;
        res |= helper(board, word, row + 1, col, index + 1, visited);
        res |= helper(board, word, row - 1, col, index + 1, visited);
        res |= helper(board, word, row, col + 1, index + 1, visited);
        res |= helper(board, word, row, col - 1, index + 1, visited);

        return res;
    }
};
