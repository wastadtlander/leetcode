class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, count = nums[0] > 0 ? 1 : 0;
        while (i < n) {
            if (i + 1 > nums[i] && (i == n - 1 || (i != n - 1 && i + 1 < nums[i + 1]))) {
                count++;
            }
            i++;
        }
        return count;
    }
};
