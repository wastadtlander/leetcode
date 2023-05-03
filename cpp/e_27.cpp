class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            while (r >= 0 && nums[r] == val) r--;
            if (l < r && r >= 0 && nums[l] == val) nums[l] = nums[r--];
            l++;
        }
        return r + 1;
    }
};
