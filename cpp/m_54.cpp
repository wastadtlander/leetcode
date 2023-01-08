class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int i = 0, j = -1;
        while (ret.size() != matrix.size() * matrix[0].size()) {
            while (++j < matrix[0].size() && matrix[i][j] != -101) {
                ret.push_back(matrix[i][j]);
                matrix[i][j] = -101;
            }
            j--;
            while (++i < matrix.size() && matrix[i][j] != -101) {
                ret.push_back(matrix[i][j]);
                matrix[i][j] = -101;
            }
            i--;
            while (--j >= 0 && matrix[i][j] != -101) {
                ret.push_back(matrix[i][j]);
                matrix[i][j] = -101;
            }
            j++;
            while (--i >= 0 && matrix[i][j] != -101) {
                ret.push_back(matrix[i][j]);
                matrix[i][j] = -101;
            }
            i++;
        }
        return ret;
    }
};
