class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> costs;
        for (int i = 97; i < 123; i++) costs[i] = i - 96;
        for (int i = 0; i < chars.size(); i++) costs[chars[i]] = vals[i];
        vector<int> dp(s.size(), 0);
        int running = 0, m = 0;
        for (char c : s) {
            running += costs[c];
            m = max(m , running);
            if (running < 0) running = 0;        
        }
        return m;
    }
};
