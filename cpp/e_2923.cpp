class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> win(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    win[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (win[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
