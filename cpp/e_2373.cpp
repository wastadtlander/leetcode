class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (i + 2 < n && j + 2 < n) {
                    maxLocal[i][j] = max({grid[i][j], grid[i + 1][j], grid[i + 2][j], grid[i][j + 1], grid[i][j + 2], grid[i + 1][j + 1], grid[i + 1][j + 2], grid[i + 2][j + 1], grid[i + 2][j + 2]});
                }
            }
        }
        return maxLocal;
    }
};
