class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), ret = 0, rightEvenSum = 0, rightOddSum = 0, leftEvenSum = 0, leftOddSum = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 ==0) rightEvenSum += nums[i];
            else rightOddSum += nums[i];
        }
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) rightEvenSum -= nums[i];
            else rightOddSum -= nums[i];
            if (leftEvenSum + rightOddSum == leftOddSum + rightEvenSum) ret++;
            if (i % 2 == 0) leftEvenSum += nums[i];
            else leftOddSum += nums[i];
        }
        return ret;
    }
};
