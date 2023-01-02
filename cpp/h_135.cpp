class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> idx(ratings.size()), count(ratings.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return ratings[i] < ratings[j];
        });
        for (int i : idx) {
            if (i == 0 && ratings[i] > ratings[i + 1]) {
                count[i] = count[i + 1] + 1;
            } else if (i == ratings.size() - 1 && ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            } else if (i != 0 && i != ratings.size() - 1 && (ratings[i] > ratings[i - 1] || ratings[i] > ratings[i + 1])) {
                if (ratings[i] == ratings[i - 1]) {
                    count[i] = count[i + 1] + 1;
                } else if (ratings[i] == ratings[i + 1]) {
                    count[i] = count[i - 1] + 1;
                } else {
                    count[i] = max(count[i - 1], count[i + 1]) + 1;
                }
            } else {
                count[i] = 1;
            }
        }
        return accumulate(count.begin(), count.end(), 0);
    }
};
