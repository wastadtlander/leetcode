class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            steps++;
            if (s[s.size() - 1] == '1') {
                int i = s.size() - 1;
                while (i >= 0 && s[i] != '0') {
                    s[i] = '0';
                    i--;
                }
                if (i == -1) {
                    s = '1' + s;
                } else {
                    s[i] = '1';
                }
            } else {
                s.pop_back();
            }
        }
        return steps;
    }
};
