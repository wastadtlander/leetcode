class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                umap[nums[i] * nums[j]]++;
                ret += (umap[nums[i] * nums[j]] - 1) * 8;
            }
        }
        return ret;
    }
};
