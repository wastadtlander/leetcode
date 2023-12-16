class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size(), m = nums.size(), j = 0;
        for (int i = 0; i < n;) {
            while (j < m && nums[j] != groups[i][0]) j++;
            int k = 0, nLocal = groups[i].size(), jStart = j;
            while (j < m && k < nLocal && nums[j] == groups[i][k]) {
                j++;
                k++;
            }
            if (k != nLocal && j == m) return false;
            else if (k == nLocal) i++;
            else j = jStart + 1;
        }
        return true;
    }
};
