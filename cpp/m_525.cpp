// -1, -2, -1, -2, -3, -2, -3, -4, -5, -4, -5, -4, -5, -6, -7, -8, -9, -8, -7, -6, -7, -8, -9
// Sum as you go and if you find the same sum as before calculate the difference between their indexes.
// Need the umap to default to {0, -1} because non-inclusive.
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, m = 0;
        unordered_map<int, int> umap{{0, -1}};
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (umap.count(sum)) {
                m = max(m, i - umap[sum]);
            } else {
                umap[sum] = i;
            }
        }
        return m;
    }
};
