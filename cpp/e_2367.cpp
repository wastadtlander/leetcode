class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        unordered_set<int> count;
        for (int num : nums) {
            if (count.count(num - diff) && count.count(num - 2 * diff)) {
                ans++;
            }
            count.insert(num);
        }
        return ans;
    }
};
