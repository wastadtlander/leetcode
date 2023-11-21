class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> ret;
        ret.push_back(s);
        permute(s, n, 0, ret);
        return ret;
    }

    void permute(string s, int n, int i, vector<string>& ret) {
        if (i == n) return;
        if (isalpha(s[i])) {
            permute(s, n, i + 1, ret);
            if (s[i] >= 'a') s[i] -= 32;
            else s[i] += 32;
            ret.push_back(s);
        }
        permute(s, n, i + 1, ret);
    }
};
