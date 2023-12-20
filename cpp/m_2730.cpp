class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size(), l = 0, r = 1, ans = 1, count = 0;
        while (r < n) {
            if (s[r] == s[r - 1]) count++;
            ans = max(ans, count == 2 ? r - l : r - l + 1);
            while (count == 2) {
                if (s[l] == s[l + 1]) count--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
