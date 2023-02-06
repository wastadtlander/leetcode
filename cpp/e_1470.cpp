class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(n * 2);
        int i = 0, j = n;
        for (int x = 0; x < nums.size(); x++, i++, j++) {
            ret[x++] = nums[i];
            ret[x] = nums[j];
        }
        return ret;
    }
};
