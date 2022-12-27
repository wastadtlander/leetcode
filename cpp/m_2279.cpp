class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> arr(capacity.size());
        for (int i = 0; i < capacity.size(); i++) {
            arr[i] = capacity[i] - rocks[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (additionalRocks >= arr[i]) {
                additionalRocks -= arr[i];
                arr[i] = 0;
            } else {
                break;
            }
        }
        return count(arr.begin(), arr.end(), 0);
    }
};
