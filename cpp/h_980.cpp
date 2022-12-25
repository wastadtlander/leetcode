class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> startingSquare, endingSquare;
        int cantWalk = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startingSquare.first = i;
                    startingSquare.second = j;
                } else if (grid[i][j] == 2) {
                    endingSquare.first = i;
                    endingSquare.second = j;
                } else if (grid[i][j] == -1) {
                    cantWalk++;
                }
            }
        }

        int count = 0;

        vector<vector<int>> vis = grid;

        dfs(grid, vis, endingSquare, cantWalk, 0, startingSquare.first, startingSquare.second, count);

        return count;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, pair<int, int>& endingSquare, int& cantWalk, int visited, int x, int y, int& count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || vis[x][y] == 3 || vis[x][y] == -1) return;
        
        if (x == endingSquare.first && y == endingSquare.second && visited == (grid.size() * grid[0].size()) - cantWalk - 1) {
            count++;
            return;
        }

        vis[x][y] = 3;

        visited++;

        dfs(grid, vis, endingSquare, cantWalk, visited, x + 1, y, count);
        dfs(grid, vis, endingSquare, cantWalk, visited, x - 1, y, count);
        dfs(grid, vis, endingSquare, cantWalk, visited, x, y + 1, count);
        dfs(grid, vis, endingSquare, cantWalk, visited, x, y - 1, count);

        vis[x][y] = 0;
    }
};
