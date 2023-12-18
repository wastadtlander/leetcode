class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans = 0;
        for (int n : nums) {
            freq[n]++;
            if (freq[n - 1]) {
                ans = max(ans, freq[n - 1] + freq[n]);
            }
            if (freq[n + 1]) {
                ans = max(ans, freq[n + 1] + freq[n]);
            }
        }
        return ans;
    }
};
