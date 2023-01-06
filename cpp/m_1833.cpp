class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ret = 0;
        for (int c : costs) {
            if (coins - c >= 0) {
                coins -= c;
                ret++;
            } else break;
        }
        return ret;
    }
};
