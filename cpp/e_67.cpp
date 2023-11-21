class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ret;
        int idx = 0, n = a.size(), m = b.size(), carry = 0;
        while (idx < n && idx < m) {
            if (a[idx] == '0' && b[idx] == '0') {
                if (carry) {
                    carry = 0;
                    ret.push_back('1');
                } else {
                    ret.push_back('0');
                }
            } else if ((a[idx] == '1' && b[idx] == '0') || (b[idx] == '1' && a[idx] == '0')) {
                if (carry) {
                    ret.push_back('0');
                } else {
                    ret.push_back('1');
                }
            } else {
                if (carry) {
                    ret.push_back('1');
                } else {
                    carry = 1;
                    ret.push_back('0');
                }
            }
            idx++;
        }
        while (idx < n) {
            if (a[idx] == '0') {
                if (carry) {
                    carry = 0;
                    ret.push_back('1');
                } else {
                    ret.push_back('0');
                }
            } else {
                if (carry) {
                    carry = 1;
                    ret.push_back('0');
                } else {
                    ret.push_back('1');
                }
            }
            idx++;
        }
        while (idx < m) {
            if (b[idx] == '0') {
                if (carry) {
                    carry = 0;
                    ret.push_back('1');
                } else {
                    ret.push_back('0');
                }
            } else {
                if (carry) {
                    carry = 1;
                    ret.push_back('0');
                } else {
                    ret.push_back('1');
                }
            }
            idx++;
        }
        if (carry) {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
