class Solution {
public:
    void helper(int i, unordered_set<int>& visited, stack<int>& st, unordered_map<int, vector<int>>& adj) {
        visited.insert(i);

        for (int neighbor : adj[i]) {
            if (visited.find(neighbor) == visited.end()) {
                helper(neighbor, visited, st, adj);
            }
        }

        st.push(i);
    }

    bool hasCycle(int i, unordered_set<int>& visited, unordered_set<int>& recStack, unordered_map<int, vector<int>>& adj) {
        visited.insert(i);
        recStack.insert(i);

        for (int neighbor : adj[i]) {
            if (visited.find(neighbor) == visited.end()) {
                if (hasCycle(neighbor, visited, recStack, adj)) {
                    return true;
                }
            } else if (recStack.find(neighbor) != recStack.end()) {
                return true;
            }
        }

        recStack.erase(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto& v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            if (find(adj[v[0]].begin(), adj[v[0]].end(), v[1]) != adj[v[0]].end()) return {};
        }
        stack<int> st;
        unordered_set<int> visited, visCycle, recStack;

        for (int i = 0; i < numCourses; ++i) {
            if (hasCycle(i, visCycle, recStack, adj)) {
                return {};
            }
            if (visited.find(i) == visited.end()) {
                helper(i, visited, st, adj);
            }
        }

        vector<int> ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }

        return ret;
    }
};
