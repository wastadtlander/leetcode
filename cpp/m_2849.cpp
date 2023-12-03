class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minTimeToReach = max(abs(sx - fx), abs(sy - fy));
        if (minTimeToReach == 0 && t == 1) return false;
        return minTimeToReach <= t;
    }
};
