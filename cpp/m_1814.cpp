class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), mod = 1000000007;
        long ret = 0;
        unordered_map<int, int> reverseHash;
        for (int num : nums) {
            string n = to_string(num);
            reverse(n.begin(), n.end());
            int numRev = stoi(n);
            reverseHash[num - numRev]++;
            if (reverseHash[num - numRev] > 1) {
                ret += reverseHash[num - numRev] - 1;
            }
        }
        return ret % mod;
    }
};
