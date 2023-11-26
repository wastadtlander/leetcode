class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ret = 0;
        vector<vector<int>> count(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && matrix[i][j] == 1) {
                    count[i][j]++;
                } else if (matrix[i][j] == 1){
                    count[i][j] = count[i - 1][j] + matrix[i][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            sort(count[i].begin(), count[i].end(), greater<int>());
            for (int j = 0; j < n; ++j) {
                ret = max(ret, count[i][j] * (j + 1));
            }
        }
        return ret;
    }
};
