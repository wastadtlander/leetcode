class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int lastM = 0, lastP = 0, lastG = 0, totalCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (char c : garbage[i]) {
                if (c == 'M') {
                    lastM = max(lastM, i);
                } else if (c == 'P') {
                    lastP = max(lastP, i);
                } else {
                    lastG = max(lastG, i);
                }
            }
            totalCount += garbage[i].size();
        }
        return totalCount + 
                accumulate(travel.begin(), travel.begin() + lastM, 0) +
                accumulate(travel.begin(), travel.begin() + lastP, 0) + 
                accumulate(travel.begin(), travel.begin() + lastG, 0);
    }
};
