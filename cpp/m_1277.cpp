class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] && i && j) {
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
                }
                ret += matrix[i][j];
            }
        }
        return ret;
    }
};
