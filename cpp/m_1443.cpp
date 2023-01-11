class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (vector v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> v(n);
        int t = 0;
        dfs(adj, hasApple, v, t, 0);
        return t;
    }

    bool dfs(vector<vector<int>>& adj, vector<bool>& hasApple, vector<int>& v, int& t, int n) {
        v[n] = 1;
        bool foundApple = hasApple[n];
        for (int node : adj[n]) {
            if (v[node] == 0) {
                t++;
                if (dfs(adj, hasApple, v, t, node)) foundApple = true;
                else t--;
            }
        }
        if (foundApple && n != 0) t++;
        return foundApple;
    }
};
