class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> g(grid.size() * 3, vector<int>(grid.size() * 3));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '/') {
                    g[(i * 3) + 2][j * 3] = -1;
                    g[(i * 3) + 1][(j * 3) + 1] = -1;
                    g[(i * 3)][(j * 3) + 2] = -1;
                } else if (grid[i][j] == '\\') {
                    g[i * 3][j * 3] = -1;
                    g[(i * 3) + 1][(j * 3) + 1] = -1;
                    g[(i * 3) + 2][(j * 3) + 2] = -1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                if (g[i][j] == 0) {
                    dfs(g, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& g, int x, int y) {
        if (x < 0 || y < 0 || x >= g.size() || y >= g.size() || g[x][y] == -1 || g[x][y] == 1) return;

        g[x][y] = 1;

        dfs(g, x + 1, y);
        dfs(g, x - 1, y);
        dfs(g, x, y + 1);
        dfs(g, x, y - 1);
    }
};
