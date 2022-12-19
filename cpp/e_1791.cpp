class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 2);
        for (vector<int> v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return distance(adj.begin(), max_element(adj.begin(), adj.end(), [&](vector<int>& a, vector<int>& b) {
            return a.size() < b.size();
        }));
    }
};
