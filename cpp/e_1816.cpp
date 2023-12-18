class Solution {
public:
    string truncateSentence(string s, int k) {
        istringstream ss(s);
        string ans, t;
        while (k && ss >> t) {
            ans += t + ' ';
            k--;
        }
        ans.pop_back();
        return ans;
    }
};
