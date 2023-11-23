class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ret = 0;
        for (int n : nums) {
            int divisor = 0;
            for (int d = 2; d * d <= n; ++d) {
                if (n % d == 0) {
                    if (!divisor) {
                        divisor = d;
                    } else {
                        divisor = 0;
                        break;
                    }
                }
            }
            if (divisor != 0 && divisor != n / divisor) {
                ret += 1 + n + divisor + n / divisor;
            }
        }
        return ret;
    }
};
