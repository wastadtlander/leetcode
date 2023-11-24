class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            bitset<32> t(i);
            if (t.count() == k) sum += nums[i];
        }
        return sum;
    }
};
