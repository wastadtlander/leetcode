class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int maxElement = *max_element(vals.begin(), vals.end());
        if (edges.size() == 0) return maxElement;
        unordered_map<int, priority_queue<int>> adj;
        for (auto &edge : edges) {
            adj[edge[0]].push(vals[edge[1]]);
            adj[edge[1]].push(vals[edge[0]]);
        }
        int ret = INT_MIN;
        for (auto &p : adj) {
            int localMax = vals[p.first], localK = k;
            while (!p.second.empty() && p.second.top() > 0 && localK > 0) {
                localMax += p.second.top();
                p.second.pop();
                localK--;
            }
            ret = max(ret, localMax);
        }
        return ret > 0 ? ret : maxElement;
    }
};
