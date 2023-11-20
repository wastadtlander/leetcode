class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = k - 1, runningSum = 0;
        double ret = -DBL_MAX;
        runningSum = accumulate(nums.begin(), nums.begin() + k, 0);
        while (r < n - 1) {
            ret = max(ret, runningSum / (k * 1.0));
            runningSum += nums[++r];
            runningSum -= nums[l++];
        }
        return max(ret, runningSum / (k * 1.0));
    }
};
