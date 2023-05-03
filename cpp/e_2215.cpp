class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        unordered_map<int, int> umap;
        for (int n : s1) umap[n]++;
        for (int n : s2) umap[n]--;
        vector<vector<int>> ret(2);
        for (pair p : umap) {
            if (p.second == 1) ret[0].push_back(p.first);
            else if (p.second == -1) ret[1].push_back(p.first);
        }
        return ret;
    }
};
