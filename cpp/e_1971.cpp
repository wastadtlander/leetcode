class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) return true;

        vector<vector<int>> adj(n);

        for (vector<int> v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<int> v(n, 0);
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            if (q.front() == destination) {
                return true;
            }

            v[q.front()] = 1;

            for (int num : adj[q.front()]) {
                if (v[num] == 0) {
                    q.push(num);
                }
            }

            q.pop();
        }
        return false;
    }
};
