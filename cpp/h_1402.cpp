class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int s = 0, ret = 0, running = 0;
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            running += s + satisfaction[i];
            s += satisfaction[i];
            ret = max(ret, running);
        }
        return ret;
    }
};
