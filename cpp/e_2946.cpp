class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        if (k == 0) return true;
        vector<vector<int>> comp = mat;
        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                reverse(comp[i].rbegin(), comp[i].rbegin() + k);
                reverse(comp[i].rbegin() + k, comp[i].rend());
                reverse(comp[i].begin(), comp[i].end());
            } else {
                reverse(comp[i].begin(), comp[i].begin() + k);
                reverse(comp[i].begin() + k, comp[i].end());
                reverse(comp[i].begin(), comp[i].end());
            }
        }
        return mat == comp;
    }
};
