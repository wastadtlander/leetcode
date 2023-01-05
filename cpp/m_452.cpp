class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; });
        int ret = 1, end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                ret++;
                end = points[i][1];
            }
        }
        return ret;
    }
};
