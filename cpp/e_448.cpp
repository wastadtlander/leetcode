class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int, int> umap;

        for (int n : nums) {
            umap[n]++;
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (umap.find(i) == umap.end()) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
