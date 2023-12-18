class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size(), maxOne = INT_MIN, maxTwo = INT_MIN, minOne = INT_MAX, minTwo = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > maxOne) {
                maxTwo = maxOne;
                maxOne = nums[i];
            } else if (nums[i] > maxTwo) {
                maxTwo = nums[i];
            }
            if (nums[i] < minOne) {
                minTwo = minOne;
                minOne = nums[i];
            } else if (nums[i] < minTwo) {
                minTwo = nums[i];
            }
        }
        return (maxOne * maxTwo) - (minOne * minTwo);
    }
};
