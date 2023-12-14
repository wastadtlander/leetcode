class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int chocOne = INT_MAX, chocTwo = INT_MAX;
        for (int n : prices) {
            if (n < chocOne) {
                chocTwo = chocOne;
                chocOne = n;
            } else if (n < chocTwo) {
                chocTwo = n;
            }
        }
        return money - chocTwo - chocOne >= 0 ? money - chocTwo - chocOne : money;
    }
};
