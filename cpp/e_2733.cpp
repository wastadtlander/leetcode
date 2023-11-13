class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2) return -1;
        int mi = nums[0], ma = nums[0], ot = nums[0];
        for (auto i = 1; i < 3; ++i) {
            if (nums[i] > ma) {
                mi = ot;
                ot = ma;
                ma = nums[i];
            } else if (nums[i] < mi) {
                ma = ot;
                ot = mi;
                mi = nums[i];
            } else {
                ot = nums[i];
            }
        } 
        return ot;
    }
};
