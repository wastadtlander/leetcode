class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_set<int> found;
        sort(nums.begin(), nums.end());
        int smallestNum = nums[0], count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == smallestNum) continue;
            found.insert(nums[i]);
            count += found.size();
        }
        return count;
    }
};
