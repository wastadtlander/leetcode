class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [&](string& s1, string& s2) { return s1.size() > s2.size() || (s1.size() == s2.size() && s1 < s2); });
        string ret = "";
        for (int i = 0; i < dictionary.size(); i++) {
            int p = 0, j = 0;
            for (; j < dictionary[i].size(); j++) {
                while (p < s.size() && s[p] != dictionary[i][j]) p++;
                if (p == s.size()) break;
                p++;
            }
            if (j == dictionary[i].size()) {
                ret = dictionary[i];
                break;
            }  
        }
        return ret;
    }
};