class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long l = 0, r = 0, localCount = 0, res = 1;
        while (r < nums.size()) {
            localCount += nums[r];
            while ((r - l + 1) * nums[r] > localCount + k) {
                localCount -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
