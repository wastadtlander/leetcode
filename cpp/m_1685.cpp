class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), leftSum;
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = (sum - (n - i) * nums[i]) + (i * nums[i] - leftSum);
            leftSum += nums[i];
            sum -= nums[i];
        }
        return ret;
    }
};
