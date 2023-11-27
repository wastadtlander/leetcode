class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> c;
        for (int n : nums) {
            if (n != 0) c.insert(n);
        }
        return c.size();
    }
};
