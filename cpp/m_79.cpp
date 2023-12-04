class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string& word, int idx, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;

        if (idx == word.size() - 1 && board[i][j] == word[idx]) {
            return true;
        }

        char hold = board[i][j];
        board[i][j] = '-';

        bool s = search(board, word, idx + 1, i + 1, j) || 
                search(board, word, idx + 1, i - 1, j) || 
                search(board, word, idx + 1, i, j + 1) ||
                search(board, word, idx + 1, i, j - 1);

        board[i][j] = hold;
        return s;
    }
};
