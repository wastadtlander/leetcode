class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int count = 0, sum = 0;
        unordered_set<int> uset;
        uset.insert(0);
        for (int n : nums) {
            sum += n;
            if (uset.count(sum - target)) {
                uset = {0};
                sum = 0;
                count++;
            } else {    
                uset.insert(sum);
            }
        }
        return count;
    }
};
