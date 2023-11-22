class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp(1);
        int ret = 0;
        for (string s : arr) {
            bitset<26> sBitset;
            for (char c : s) sBitset.set(c - 'a');
            int n = sBitset.count();
            if (n < s.size()) continue;
            for (int i = dp.size() - 1; i >= 0; --i) {
                bitset temp = dp[i];
                if ((sBitset & temp).any()) continue;
                dp.push_back(sBitset | temp);
                ret = max(ret, (int)temp.count() + n);
            }
        }
        return ret;
        // int n = arr.size();
        // vector<unordered_set<char>> hash(n);
        // for (int i = 0; i < n; ++i) {
        //     for (char c : arr[i]) hash[i].insert(c);
        //     for (int j = 0; j < i; ++j) {
        //         bool isValid = true;
        //         for (char c : hash[j]) {
        //             if (hash[i].count(c)) {
        //                 isValid = false;
        //                 break;
        //             }
        //         }
        //         if (isValid) {
        //             for (char c : hash[i]) hash[j].insert(c);
        //         }
        //     }
        // }
        // return (*max_element(hash.begin(), hash.end(), [](auto a, auto b) {
        //     return a.size() > b.size();
        // })).size();
    }
};
