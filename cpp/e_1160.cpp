class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charMap(26, 0);
        for (char c : chars) {
            charMap[c - 'a']++;
        }
        int count = 0;
        for (string str : words) {
            vector<int> tempMap = charMap;
            bool isValid = true;
            for (char c : str) {
                if (tempMap[c - 'a'] >= 1) {
                    tempMap[c - 'a']--;
                } else {
                    isValid = false;
                }
            }
            if (isValid) count += str.size();
        }
        return count;
    }
};
