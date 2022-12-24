class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (vector<int> v : edges) {
            adj[v[1]].push_back(v[0]);
        }
        vector<int> ret;
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].empty()) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
