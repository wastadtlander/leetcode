class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ret;
        for (int i = 0; i < n; ++i) {
            vector<int> curr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(curr.begin(), curr.end());
            int diff = abs(curr[0] - curr[1]);
            bool isValid = true;
            for (int j = 2; j < curr.size(); ++j) {
                if (abs(curr[j] - curr[j - 1]) != diff) {
                    isValid = false;
                    break;
                }
            }
            ret.push_back(isValid);
        }
        return ret;
    }
};
