class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
            while (n > 0) {
                sum -= n % 10;
                n /= 10;
            }
        }
        return sum;
    }
};
