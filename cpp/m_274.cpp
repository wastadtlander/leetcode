class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int m = 0;
        for (int i = citations.size() - 1; i >= 0; i--) {
            m = max(m, min(static_cast<int>(citations.size() - i), citations[i]));
        }
        return m;
    }
};
