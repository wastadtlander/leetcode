class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int x = 0; x < board.size(); ++x) {
            for (int y = 0; y < board[0].size(); ++y) {
                int count = 0;
                if (x != 0) count += board[x - 1][y] >= 1 ? 1 : 0;
                if (x != 0 && y != board[0].size() - 1) count += board[x - 1][y + 1] >= 1 ? 1 : 0;
                if (y != board[0].size() - 1) count += board[x][y + 1] >= 1 ? 1 : 0;
                if (x != board.size() - 1 && y != board[0].size() - 1) count += board[x + 1][y + 1] >= 1 ? 1 : 0;
                if (x != board.size() - 1) count += board[x + 1][y] >= 1 ? 1 : 0;
                if (x != board.size() - 1 && y != 0) count += board[x + 1][y - 1] >= 1 ? 1 : 0;
                if (y != 0) count += board[x][y - 1] >= 1 ? 1 : 0;
                if (x != 0 && y != 0) count += board[x - 1][y - 1] >= 1 ? 1 : 0;
                if (count && board[x][y] == 1) board[x][y] = count;
                else if (count) board[x][y] = -1 * count;
            }
        }
        for (int x = 0; x < board.size(); ++x) {
            for (int y = 0; y < board[0].size(); ++y) {
                if (board[x][y] == 2 || board[x][y] == 3 || board[x][y] == -3) board[x][y] = 1;
                else board[x][y] = 0;
            }
        }
    }
};
