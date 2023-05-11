class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1, m = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            m = max(m, min(static_cast<int>(citations.size() - mid), citations[mid]));
            if (citations[mid] <= citations[mid] - mid || citations[mid] <= m) left = mid + 1;
            else right = mid - 1;
        }

        return m;
    }
};
