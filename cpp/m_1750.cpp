class Solution {
public:
    int minimumLength(string s) {
        if (s.size() == 1) return 1;
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            char curr = s[l];
            if (s[r] != curr) break;
            while (l <= r && s[l] == curr) l++;
            while (l <= r && s[r] == curr) r--;
        }
        if (l > r && s[r - 1] != s[r] && s[r + 1] != s[r]) return 1;
        return r - l + 1;
    }
};
