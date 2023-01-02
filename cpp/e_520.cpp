class Solution {
public:
    bool detectCapitalUse(string word) {
        bool foundLower = islower(word[word.size() - 1]) ? true : false;
        for (int i = 1; i < word.size(); i++) {
            if (islower(word[i])) foundLower = true;
            if (islower(word[0]) && isupper(word[i])) return false;
            else if (isupper(word[i]) && foundLower) return false;
        }
        return true;
    }
};
