class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        int min1 = 10, min2 = 10, min3 = 10;
        for (int n : nums1) {
            umap[n]++;
            min1 = min(min1, n);
        }
        for (int n : nums2) {
            umap[n]++;
            if (umap[n] == 2) min3 = min(min3, n);
            min2 = min(min2, n);
        }
        return min3 != 10 ? min3 : min((min1 * 10) + min2, (min2 * 10) + min1);
    }
};
