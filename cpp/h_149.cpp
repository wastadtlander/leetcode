class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ret = 1;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<float, int> umap;
            int m = 0;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                float slope = points[j][0] - points[i][0] != 0 ? (float)(points[j][1] - points[i][1]) / (float)(points[j][0] - points[i][0]) : 10001;
                umap[slope]++;
                m = max(m, umap[slope] + 1);
            }
            ret = max(ret, m);
        }
        return ret;
    }
};
