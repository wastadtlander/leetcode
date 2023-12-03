class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int sum = 1, count = 0, i = 0;
        while (sum <= target) {
            if (i < coins.size() && coins[i] <= sum) {
                sum += coins[i];
                i++;
            } else {
                sum *= 2;
                count++;
            }
        }
        return count;
    }
};
