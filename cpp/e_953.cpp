class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> charHash;
        for (int i = 0; i < order.size(); ++i) charHash[order[i]] = i + 1; 
        for (int i = 1; i < words.size(); ++i) {
            int idx = 0;
            while (idx < words[i].size() && idx < words[i - 1].size()) {
                if (charHash[words[i - 1][idx]] > charHash[words[i][idx]]) return false;
                else if (charHash[words[i - 1][idx]] < charHash[words[i][idx]]) break;
                else idx++;
            }
            if (idx < words[i - 1].size() && idx >= words[i].size()) return false;
        }
        return true;
    }
};
