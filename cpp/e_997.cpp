class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1) {
            return 1;
        } else if (trust.empty()) {
            return -1;
        }
        unordered_map<int, int> umap;
        for (vector<int> v : trust) {
            umap[v[0]]--;
            umap[v[1]]++;
        }
        for (auto p : umap) {
            if (p.second == n - 1) {
                return p.first;
            }
        }
        return -1;
    }
};
