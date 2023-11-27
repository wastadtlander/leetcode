class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        int mod = 1000000007;
        vector<long long> dp(9, 1);
        for (int i = 2; i <= n; ++i) {
            long long zero = dp[0];
            long long one = dp[1];
            long long two = dp[2];
            long long three = dp[3];
            long long four = dp[4];
            long long six = dp[5];
            long long seven = dp[6];
            long long eight = dp[7];
            long long nine = dp[8];
            dp[0] = (four + six) % mod;
            dp[1] = (six + eight) % mod;
            dp[2] = (seven + nine) % mod;
            dp[3] = (four + eight) % mod;
            dp[4] = (zero + three + nine) % mod;
            dp[5] = (zero + one + seven) % mod;
            dp[6] = (two + six) % mod;
            dp[7] = (one + three) % mod;
            dp[8] = (two + four) % mod;
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % mod;
    }
};
