class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp;
        dp.push_back(1);
        dp.push_back(2);
        dp.push_back(5);
        for (int i = 3; i < n; i++) {
            dp.push_back(2 * dp[i - 1] + dp[i - 3]);
            dp[i] %= (long long)1e9 + 7;
        }
        return dp[n - 1];
    }
};
