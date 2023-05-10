class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));

        int val = 1, i = 0, j = -1, dir = 1;

        while (val <= n * n) {
            if (dir == 1) {
                j++;
                if (j == n - 1 || (j != n - 1 && ret[i][j + 1] != 0)) dir++;
            } else if (dir == 2) {
                i++;
                if (i == n - 1 || (i != n - 1 && ret[i + 1][j] != 0)) dir++;
            } else if (dir == 3) {
                j--;
                if (j == 0 || (j != 0 && ret[i][j - 1] != 0)) dir++;
            }
            else if (dir == 4) {
                i--;
                if (ret[i - 1][j] != 0) dir = 1;
            }
            ret[i][j] = val++;
        }

        return ret;
    }
};
