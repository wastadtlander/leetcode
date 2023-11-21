class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (string row : board) {
            for (char m : row) {
                if (m == 'X') xCount++;
                else if (m == 'O') oCount++;
            }
        }
        if (xCount < oCount || xCount - oCount > 1) return false;
        bool xWin = false, oWin = false;
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
                xWin = true;
            }
            if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
                oWin = true;
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
                xWin = true;
            }
            if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
                oWin = true;
            }
        }
        if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || 
            (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
            xWin = true;
        }
        if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || 
            (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
            oWin = true;
        }
        if ((xWin && xCount == oCount) || (oWin && xCount - oCount == 1)) return false;
        return xWin && oWin ? false : true;
    }
};
