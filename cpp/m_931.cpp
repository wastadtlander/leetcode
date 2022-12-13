class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return matrix[0][0];

        int minPathSum = INT_MAX;

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j == 0) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                } else if (j == matrix[0].size() - 1) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                } else {
                    matrix[i][j] += min(matrix[i - 1][j], min(matrix[i - 1][j + 1], matrix[i - 1][j - 1]));
                }

                if (i == matrix.size() - 1) minPathSum = min(minPathSum, matrix[i][j]);
            }
        }

        return minPathSum;
    }
};
