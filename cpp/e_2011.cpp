class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ret = 0;
        for (string s : operations) {
            if (s.find("++") != string::npos) {
                ret++;
            } else if (s.find("--") != string::npos) {
                ret--;
            }
        }
        return ret;
    }
};
