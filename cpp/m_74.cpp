class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), idx = 0;
        while (idx < m && target > matrix[idx][n - 1]) idx++;
        if (idx == m) return false;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[idx][mid] == target) {
                return true;
            } else if (matrix[idx][mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
