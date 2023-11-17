class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 1; i < sentence.size() - 1; ++i) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) return false;
        }
        return sentence.front() == sentence.back();
    }
};
