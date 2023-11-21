class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((long)m * m > (long)x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return round(r);
    }
};
