class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> vis(n, 0);
        for (vector<int> v : dislikes) {
            adj[v[1] - 1].push_back(v[0] - 1);
            adj[v[0] - 1].push_back(v[1] - 1);
        }
        
        for (int i = 0; i < n; i++) {
           if (vis[i] == 0 && !dfs(adj, vis, i, 1)) {
               return false;
           }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int index, int group) {
        vis[index] = group;
        
        for (int x : adj[index]) {
            if (vis[x] == group) {
                return false;
            }
            
            if (vis[x] == 0 && !dfs(adj, vis, x, group*-1)) {
                return false;
            }
        }
        
        return true;
    }
};
