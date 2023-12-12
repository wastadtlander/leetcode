class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int topOne = 0, topTwo = 0;
        for (int n : nums) {
            if (n > topOne) {
                topTwo = topOne;
                topOne = n;
            } else if (n > topTwo) {
                topTwo = n;
            }
        }
        return (topOne - 1) * (topTwo - 1);
    }
};
