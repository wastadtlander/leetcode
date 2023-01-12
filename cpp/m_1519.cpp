class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (vector v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> ret(n), c(26);
        dfs(adj, ret, c, labels, 0);
        return ret;
    }

    void dfs(vector<vector<int>>& adj, vector<int>& ret, vector<int>& c, string& labels, int node) {
        if (ret[node] == 0) {
            ret[node] = 1;
            for (int n : adj[node]) {
                vector<int> cTemp(26);
                dfs(adj, ret, cTemp, labels, n);
                for (int i = 0; i < 26; i++) {
                    c[i] += cTemp[i];
                }   
            }
            ret[node] = ++c[labels[node] - 'a'];
        }
    }
};
