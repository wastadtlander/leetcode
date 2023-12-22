class Solution {
public:
    string sortString(string s) {
        string ans = "";
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        while (!count.empty()) {
            for (char i = 'a'; i <= 'z'; ++i) {
                if (count.find(i) != count.end()) {
                    ans.push_back(i);
                    count[i]--;
                    if (count[i] == 0) {
                        count.erase(i);
                    }
                }
            }
            for (char i = 'z'; i >= 'a'; --i) {
                if (count.find(i) != count.end()) {
                    ans.push_back(i);
                    count[i]--;
                    if (count[i] == 0) {
                        count.erase(i);
                    }
                }
            }
        }
        return ans;
    }
};
