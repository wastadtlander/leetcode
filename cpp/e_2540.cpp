class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset(nums1.begin(), nums1.end());
        for (int n : nums2) {
            if (uset.count(n)) {
                return n;
            }
        }
        return -1;
    }
};
