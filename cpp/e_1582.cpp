class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] && row[i] == 1 && col[j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
