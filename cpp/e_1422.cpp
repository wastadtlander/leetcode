class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), zeros = 0, ones = count(s.begin(), s.end(), '1'), ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') zeros++;
            else ones--;
            ans = max(ans, zeros + ones);
        }
        return ans;
    }
};
