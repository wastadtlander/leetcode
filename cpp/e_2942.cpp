class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (find(words[i].begin(), words[i].end(), x) != words[i].end()) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
