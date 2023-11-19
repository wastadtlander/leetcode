class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hash1, hash2;
        istringstream wordParse1(s1), wordParse2(s2);
        string word;
        while (getline(wordParse1, word, ' ')) {
            hash1[word]++;
        }
        while (getline(wordParse2, word, ' ')) {
            hash2[word]++;
        }
        unordered_set<string> words;
        for (auto& p : hash1) {
            if (p.second == 1 && hash2.find(p.first) == hash2.end()) words.insert(p.first);
        }
        for (auto& p : hash2) {
            if (p.second == 1 && hash1.find(p.first) == hash1.end()) words.insert(p.first);
        }
        vector<string> ret(words.begin(), words.end());
        return ret;
    }
};
