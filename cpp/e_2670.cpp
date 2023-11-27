class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prefix, suffix;
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            suffix[nums[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            prefix[nums[i]]++;
            suffix[nums[i]]--;
            if (suffix[nums[i]] == 0) {
                suffix.erase(nums[i]);
            }
            ret[i] = prefix.size() - suffix.size();
        }
        return ret;
    }
};
