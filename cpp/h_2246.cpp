class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int ret = 0, n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        dfs(adj, s, ret, 0);
        return ret;
    }

    int dfs(vector<vector<int>>& adj, string& s, int& ret, int node) {
        int b1 = 0, b2 = 0;;
        for (int n : adj[node]) {
            int c = dfs(adj, s, ret, n);
            if (s[n] == s[node]) continue;
            if (c > b2) b2 = c;
            if (b2 > b1) swap(b1, b2);
        }
        ret = max(ret, b1 + b2 + 1);
        return b1 + 1;
    }
};
