class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ret(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }

            if (!s.empty()) {
                ret[i] = s.top() - i;
            }
             
            s.push(i);
        }
        return ret;
    }
};
