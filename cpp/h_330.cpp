class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sum = 1, count = 0, i = 0;
        while (sum <= n) {
            if (i < nums.size() && nums[i] <= sum) {
                sum += nums[i];
                i++;
            } else {
                sum *= 2;
                count++;
            }
        }
        return count;
    }
};
