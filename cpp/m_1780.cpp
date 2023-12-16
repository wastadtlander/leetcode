class Solution {
public:
    bool checkPowersOfThree(int n) {
        int sum = 0;
        for (int i = 20; i >= 0; --i) {
            if (sum + pow(3, i) <= n) {
                sum += pow(3, i);
                if (sum == n) return true;
            }
        }
        return false;
    }
};
