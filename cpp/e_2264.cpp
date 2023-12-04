class Solution {
public:
    string largestGoodInteger(string num) {
        int r = 2, n = num.size();
        string ans = "";
        while (r < n) {
            if (num[r] == num[r - 1] && num[r] == num[r - 2] && num[r - 1] == num[r - 2]) {
                char n = num[r];
                string newAns = string(3, n);
                if (newAns > ans) {
                    ans = newAns;
                }
                r += 3;
            } else {
                r++;
            }
        }
        return ans;
    }
};
