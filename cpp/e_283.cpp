class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool isValid = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0 && nums[i + 1] != 0) {
                swap(nums[i], nums[i + 1]);
                isValid = false;
            }
        }
        if (!isValid) moveZeroes(nums);
    }
};
