class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += (columnTitle[i] - '@') * pow(26, n - i - 1);
        }
        return ret;
    }
};
