class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size(), m = *max_element(nums.begin(), nums.end()), ans = 0;
        queue<long long> mIdx;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == m) {
                mIdx.push(i);
                if (mIdx.size() > k) mIdx.pop();
            }
            if (mIdx.size() == k) ans += mIdx.front() + 1;
        }
        return ans;
    }
};
