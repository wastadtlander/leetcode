class Solution {
public:
    long long minimumSteps(string s) {
        long long idx = 0, blockedSpace = 0, swapsNeeded = 0;
        while (idx < s.size() && s[idx] != '1') {
            idx++;
            blockedSpace++;
        }
        for (int i = idx; i < s.size(); ++i) {
            if (s[i] == '0') {
                swapsNeeded += i - blockedSpace;
                blockedSpace++;
            }
        } 
        return swapsNeeded;
    }
};
