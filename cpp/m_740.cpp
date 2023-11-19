class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> values(10001);
        for (int n : nums) values[n] += n;
        vector<int> dp(10001);
        dp[0] = values[0];
        dp[1] = values[1];
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(values[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};
