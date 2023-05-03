class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size() - 1] < 9) {
            digits[digits.size() - 1]++;
            return digits;
        }
        int i = digits.size() - 1;
        while (i >= 1 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }
        if (i == 0 && digits[i] == 9) {
            digits.push_back(0);
            digits[i] = 1;
        } else {
            digits[i] += 1;
        }
        return digits;
    }
};
