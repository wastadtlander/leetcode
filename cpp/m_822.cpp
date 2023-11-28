class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        unordered_set<int> definiteSame;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                definiteSame.insert(fronts[i]);
            }
        }
        int ret = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!definiteSame.count(fronts[i])) {
                ret = min(ret, fronts[i]);
            }
            if (!definiteSame.count(backs[i])) {
                ret = min(ret, backs[i]);
            }
        }
        return ret == INT_MAX ? 0 : ret;    
    }
};
