class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;
        for (vector<string> path : paths) {
            cities.insert(path[0]);
        }
        string ans = "";
        for (vector<string> path : paths) {
            if (cities.count(path[1]) == 0) {
                ans = path[1];
            }
        }
        return ans;
    }
};
