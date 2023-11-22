class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> umap;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                umap[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> ret;
        for (auto& p : umap) {
            for (auto i = p.second.rbegin(); i < p.second.rend(); ++i) {
                ret.push_back(*i);
            }
        }
        return ret;
    }
};
