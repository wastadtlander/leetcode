class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int distance = abs(target[0]) + abs(target[1]);
        for (vector<int> v : ghosts) {
            if (abs(v[0] - target[0]) + abs(v[1] - target[1]) <= distance) {
                return false;
            }
        }
        return true;    
    }
};
