class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] - ans > 0) {
                ans++;
            }
        }
        return ans;
    }
};
