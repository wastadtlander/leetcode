class Solution {
public:
    int helper(vector<vector<int>>& grid, int row, int col, int k) {
        int sum = 0;
        for (int i = row; i < row + k; ++i) sum += grid[i][col];
        
        int tempSum = 0;
        for (int i = row; i < row + k; ++i) {
            tempSum = 0;
            for (int j = col; j < col + k; ++j) {
                tempSum += grid[i][j];
            }
            if (tempSum != sum) return 0;
        }

        for (int j = col; j < col + k; ++j) {
            tempSum = 0;
            for (int i = row; i < row + k; ++i) {
                tempSum += grid[i][j];
            }
            if (tempSum != sum) return 0;
        }

        tempSum = 0;
        for (int i = row, j = col; i < row + k; ++i, ++j) {
            tempSum += grid[i][j];
        }
        if (tempSum != sum) return 0;
        

        tempSum = 0;
        for (int i = row, j = col + k - 1; i < row + k; ++i, --j) {
            tempSum += grid[i][j];
        }
        if (tempSum != sum) return 0;

        return k;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = min(m - i, n - j);
                while (k) {
                    if (ret >= k) break;
                    int m = helper(grid, i, j, k);
                    ret = max(ret, m);
                    k--;
                }
            }
        }
        return ret;
    }
};
