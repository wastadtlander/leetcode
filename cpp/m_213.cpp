class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int houseOne = 0, houseTwo = 0;
        for (int i = 0; i < n - 1; ++i) {
            int house = max(houseOne + nums[i], houseTwo);
            houseOne = houseTwo;
            houseTwo = house;
        }
        int houseThree = 0, houseFour = 0;
        for (int i = 1; i < n; ++i) {
            int house = max(houseThree + nums[i], houseFour);
            houseThree = houseFour;
            houseFour = house;
        }
        return max(houseTwo, houseFour);
    }
};
