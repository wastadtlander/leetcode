class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0, numFull = numBottles, numEmpty = 0;
        while (numFull) {
            count += numFull;
            numEmpty += numFull;
            numFull = numEmpty / numExchange;
            numEmpty %= numExchange;
        }
        return count;
    }
};
