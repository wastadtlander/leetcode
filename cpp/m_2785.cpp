class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowels;
        for (char c : s) {
            char cLower = tolower(c);
            if (cLower == 'a' || cLower == 'e' || cLower == 'i' || cLower == 'o' || cLower == 'u') {
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            char cLower = tolower(s[i]);
            if (cLower == 'a' || cLower == 'e' || cLower == 'i' || cLower == 'o' || cLower == 'u') {
                s[i] = vowels[idx++];
            }
        }
        return s;
    }
};
