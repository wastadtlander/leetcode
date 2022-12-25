class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int> vis(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++) {
            cout << vis[i] << endl;
            if (vis[i] == 0) {
                count++;
                dfs(isConnected, vis, i);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node) {
        vis[node] = 1;

        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && vis[i] == 0) {
                dfs(isConnected, vis, i);
            }
        }
    }
};
