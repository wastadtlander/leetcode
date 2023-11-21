class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < n; ++i) {
            if (umap[nums[i]].size() >= 1 && i - umap[nums[i]].back() <= k) return true;
            umap[nums[i]].push_back(i);
        }
        return false;
    }
};
// Don't actually need to save as a vector only need to save the most recent one because that is the one we are checking!
