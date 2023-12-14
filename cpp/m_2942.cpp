class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int>& road : roads) {
            adj[road[0]].push_back(make_pair(road[1], road[2]));
            adj[road[1]].push_back(make_pair(road[0], road[2]));
        }
        vector<int> visited(n, 0);
        int ans = INT_MAX;
        findValidNodes(adj, visited, 1, ans);
        return ans;
    }

    void findValidNodes(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& visited, int n, int& ans) {
        if (visited[n - 1]) return;
        visited[n - 1] = 1;
        for (pair node : adj[n]) {
            ans = min(ans, node.second);
            findValidNodes(adj, visited, node.first, ans);
        }
    }
};
