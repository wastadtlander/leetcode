class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> champions(n, 0);
        for (auto& a : adj) {
            for (int e : a) {
                champions[e] = 1;
            }
        }
        int numChampions = count(champions.begin(), champions.end(), 0);
        if (numChampions == 1) {
            for (int i = 0; i < n; ++i) {
                if (champions[i] == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};
