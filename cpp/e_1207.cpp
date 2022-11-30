class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        unordered_set<int> uset;
        for (int num : arr) {
            umap[num]++;
        }
        for (pair p : umap) {
            uset.insert(p.second);
        }
        return umap.size() == uset.size();
    }
};
