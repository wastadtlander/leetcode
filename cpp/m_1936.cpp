class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        auto current = 0, rung = 0, count = 0;
        for (auto r : rungs) {
            if (r - rung > dist) count += ((r - 1) - rung) / dist;
            rung = r;
            current++;
        }
        return count;
    }
};
