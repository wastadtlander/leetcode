class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1 == s2 && s1 == s3 && s2 == s3) return 0;
        int minSize = min(s1.size(), min(s2.size(), s3.size())), count = 0;
        count += s1.size() - minSize;
        s1 = s1.substr(0, minSize);
        count += s2.size() - minSize;
        s2 = s2.substr(0, minSize);
        count += s3.size() - minSize;
        s3 = s3.substr(0, minSize);
        while (!s1.empty() && (s1 != s2 || s1 != s3 || s2 != s3)) {
            count += 3;
            s1.pop_back();
            s2.pop_back();
            s3.pop_back();
        }
        // cout << s1 << " " << s2 << " " << s3 << endl;
        return s1.empty() ? -1 : count;
    }
};
