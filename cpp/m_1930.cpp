class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, INT_MAX), last(26);
        int ret = 0;
        for (auto i = 0; i < s.size(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        for (auto i = 0; i < 26; ++i) {
            if (first[i] < last[i]) {
                ret += unordered_set<char>(s.begin() + first[i] + 1, s.begin() + last[i]).size();
            }
        }
        return ret;
    }
};
