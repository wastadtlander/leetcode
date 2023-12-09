class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size(), runningCount = 0, c = accumulate(count.begin(), count.end(), 0);
        double mi = INT_MAX, ma = INT_MIN, sum = 0, median = -1, mode = 0;
        bool findOne = false;
        for (double i = 0; i < n; ++i) {
            if (count[i] != 0) {
                runningCount += count[i];
                if (findOne) {
                    median += i;
                    median /= 2;
                    findOne = false;
                } else if (c % 2 && runningCount > c / 2 && median == -1) {
                    median = i;
                } else if (c % 2 == 0 && runningCount >= c / 2 && median == -1) {
                    median = i;
                    if (runningCount <= c / 2) {
                        findOne = true;
                    }
                }
                mi = min(mi, i);
                ma = max(ma, i);
                sum += i * count[i];
                mode = count[i] > count[mode] ? i : mode;
            }
        }
        return {mi, ma, sum / c * 1.0, median, mode};
    }
};
