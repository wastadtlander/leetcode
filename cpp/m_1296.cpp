class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        while (!s.empty()) {
            int mi = *min_element(s.begin(), s.end()), loops = mi + k;
            for (int i = mi; i < loops; ++i) {
                if (s.count(i)) {
                    freq[i]--;
                    if (freq[i] == 0) {
                        freq.erase(i);
                        s.erase(i);
                        mi++;
                    }
                } else return false;
            }
        }
        return true;
    }
};
