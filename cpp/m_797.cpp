class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        
        dfs(graph, ret, vector<int>(1, 0), 0);

        return ret;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ret, vector<int> cur, int node) {        
        if (node == graph.size() - 1) {
            ret.push_back(cur);
            return;
        }

        for (int n : graph[node]) {
            cur.push_back(n);
            dfs(graph, ret, cur, n);
            cur.pop_back();
        }
    }
};
