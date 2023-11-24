class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3, ret = 0, count = 0;
        sort(piles.begin(), piles.end());
        for (int i = piles.size() - 2; count < n; i -= 2, ++count) {
            ret += piles[i];
        }
        return ret;
    }
};
