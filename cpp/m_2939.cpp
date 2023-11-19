class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1000000007;
        if (n) {
            for (long long bit = 1LL << (n - 1); bit > 0; bit >>= 1) {
                if ((min(a, b) & bit) == 0) {
                    a ^= bit, b ^= bit;
                }
            }
        }
        return (a % mod) * (b % mod) % mod;
    }
};
