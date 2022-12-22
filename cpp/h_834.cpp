class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ret(n), child(n);
        vector<vector<int>> adj(n);

        for (vector<int> v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        calcRootAndChild(adj, ret, child, 0, -1);
        shiftAndCalcRoot(adj, ret, child, 0, -1, n);

        return ret;
    }

    void calcRootAndChild(vector<vector<int>>& adj, vector<int>& ret, vector<int>& child, int node, int parent) {
        for (int n : adj[node]) {
            if (n == parent) {
                continue;
            }
            calcRootAndChild(adj, ret, child, n, node);
            child[node] += child[n];
            ret[node] += ret[n] + child[n];
        }
        child[node] += 1;
    }

    void shiftAndCalcRoot(vector<vector<int>>& adj, vector<int>& ret, vector<int>& child, int node, int parent, int num) {
        for (int n : adj[node]) {
            if (n == parent) {
                continue;
            }
            ret[n] = ret[node] - child[n] + num - child[n];
            shiftAndCalcRoot(adj, ret, child, n, node, num);
        }
    }
};
