class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> hash;
        vector<string> res;
        for (auto& accessTime : access_times) hash[accessTime[0]].push_back(stoi(accessTime[1]));
        for (auto& p : hash) {
            sort(p.second.begin(), p.second.end());
            for (int i = 2; i < p.second.size(); ++i) {
                if (p.second[i] - p.second[i - 2] < 100) {
                    res.push_back(p.first);
                    break;
                }
            }
        }
        return res;
    }
};
