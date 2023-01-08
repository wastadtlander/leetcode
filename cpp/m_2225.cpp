class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> umap;
        for (vector<int> v : matches) {
            if (umap.find(v[0]) == umap.end()) umap[v[0]] = 0;
            umap[v[1]]++;
        }
        vector<vector<int>> ret(2);
        for (pair p : umap) {
            if (p.second == 0) ret[0].push_back(p.first);
            else if (p.second == 1) ret[1].push_back(p.first);
        }
        sort(ret[0].begin(), ret[0].end()), sort(ret[1].begin(), ret[1].end());
        return ret;
    }
};
