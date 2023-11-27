class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            while (!ret.empty() && ret.back() > nums[i] && ret.size() - 1 + n - i >= k) {
                ret.pop_back();
            }
            if (ret.size() < k) {
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};
