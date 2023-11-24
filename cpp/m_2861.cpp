class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int maxAlloy = 0, l = 1, h = 1e9;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (canCreate(n, k, budget, m, composition, stock, cost)) {
                l = m + 1;
                maxAlloy = m;
            } else {
                h = m - 1;
            }
        }
        return maxAlloy;
    }

    bool canCreate(int n, int k, int budget, int numAlloy, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        for (int i = 0; i < k; ++i) {
            long long localBudget = 0;
            for (int j = 0; j < n; ++j) {
                long long materialRequired = (1LL * composition[i][j] * numAlloy) - stock[j];
                if (materialRequired > 0) {
                    localBudget += 1LL * materialRequired * cost[j];
                }
            }
            if (localBudget <= 1LL * budget) {
                return true;
            }
        }
        return false;
    }
};
