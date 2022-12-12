class Solution {
public:
    int rob(vector<int>& nums) {
        int houseOne = 0, houseTwo = 0;
        for (int num : nums) {
            int bestHouse = max(num + houseOne, houseTwo);
            houseOne = houseTwo;
            houseTwo = bestHouse;
        }
        return houseTwo;
    }
};
