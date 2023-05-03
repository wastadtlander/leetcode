class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isalpha(s[i])) {
                int j = i - 1;
                while (j >= 0 && isalpha(s[j])) j--;
                return i - j;
            }
        }
        return 0;
    }
};
