class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before, after;
        int count = 0;
        for (int num : nums) {
            if (num == pivot) count++;
            else if (num < pivot) before.push_back(num);
            else after.push_back(num);
        }
        while (count) {
            before.push_back(pivot);
            count--;
        }
        for (int num : after) {
            before.push_back(num);
        }
        return before;
    }
};
