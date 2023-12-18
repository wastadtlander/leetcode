class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = nums[j] - nums[i];
                if (dp[i] && target * -1 <= diff && diff <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1] ? dp[n - 1] - 1: -1;
    }
};
