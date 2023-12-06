class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7, days = n % 7, money = 0;
        for (int i = 1; i <= weeks; ++i) {
            money += 28 + (7 * (i - 1));
        } 
        while (days > 0) {
            money += weeks + days;
            days--;
        }
        return money;
    }
};
