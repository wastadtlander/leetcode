class Solution {
public:
    int numberOfWays(string corridor) {
        if (count(corridor.begin(), corridor.end(), 'S') % 2 != 0) return 0;
        int n = corridor.size(), numSeats = 0, mod = 1000000007;
        long long ret = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            if (numSeats == 2) {
                if (corridor[i] == 'S') {
                    dp[i] = dp[i - 1] + 1;
                    numSeats = 1;
                    if (ret == 0) ret = 1;
                    ret = (ret * dp[i]) % mod;
                } else {
                    dp[i] = dp[i - 1] + 1;
                }
            } else if (corridor[i] == 'S') {
                numSeats++;
            }
        }
        if (numSeats == 2 && ret == 0) return 1; 
        // for (int n : dp) cout << n << " ";
        return ret % mod;
    }
};
