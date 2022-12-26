class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if (dp[0] == 0 && nums.size() != 1) return false;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] - 1);
            if (dp[i] == 0 && i != nums.size() - 1) return false;
        }
        return true;
    }
};
