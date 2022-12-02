class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> word1Vec(26);
        vector<int> word2Vec(26);
        vector<int> word3Vec(26);
        vector<int> word4Vec(26);

        for (int i = 0; i < word1.size(); i++) {
            word1Vec[word1[i] - 97]++;
            word2Vec[word2[i] - 97]++;
            word3Vec[word1[i] - 97] = 1;
            word4Vec[word2[i] - 97] = 1;
        }

        sort(word1Vec.begin(), word1Vec.end());
        sort(word2Vec.begin(), word2Vec.end());

        return word1Vec == word2Vec && word3Vec == word4Vec;
    }
};
