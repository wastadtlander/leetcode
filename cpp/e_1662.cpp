class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for (string s : word1) {
            for (char c : s) {
                str1 += c;
            }
        }
        for (string s : word2) {
            for (char c : s) {
                str2 += c;
            }
        }
        return str1 == str2;
    }
};
