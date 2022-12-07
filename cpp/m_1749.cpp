// This basically takes the two prefix sums that you get by kadane's algo and removes overlapping values
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, maximum = 0, minimum = 0;
        for (int num : nums) {
            sum += num;
            maximum = max(maximum, sum);
            minimum = min(minimum, sum);
        }
        return maximum + abs(minimum);
    }
};
