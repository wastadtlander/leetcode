class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret = 0, total = 0, running = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i], running += gas[i] - cost[i];
            if (running < 0) {
                running = 0;
                ret = i + 1;
            }
        }
        return total < 0 ? -1 : ret;
    }
};
