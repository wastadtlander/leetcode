class Solution {
public:
    int calculate(string s) {
        int i = 0, n = s.size();
        stack<string> equationStack;
        while (i < n) {
            char op = s[i];
            if (s[i] == '*' || s[i] == '/') {
                long long a = stoi(equationStack.top());
                equationStack.pop();
                while (!isdigit(s[i])) i++;
                int j = i;
                while (j < n && isdigit(s[j])) j++;
                long long b = stoi(s.substr(i, j - i));
                i = j - 1;
                if (op == '*') {
                    equationStack.push(to_string(a * b));
                } else {
                    equationStack.push(to_string(a / b));
                }
            } else if (s[i] != ' ') {
                if (s[i] == '+' || s[i] == '-') {
                    equationStack.push(to_string(s[i]));
                } else {
                    int j = i;
                    while (j < n && isdigit(s[j])) j++;
                    equationStack.push(s.substr(i, j - i));
                    i = j - 1;
                }
            }
            i++;
        }
        stack<string> equationStack2;
        while (!equationStack.empty()) {
            equationStack2.push(equationStack.top());
            equationStack.pop();
        }
        long long ans = stoi(equationStack2.top());
        equationStack2.pop();
        while (!equationStack2.empty()) {
            string op = equationStack2.top();
            equationStack2.pop();
            long long b = stoi(equationStack2.top());
            equationStack2.pop();
            if (op == "43") {
                ans += b;
            } else if (op == "45") {
                ans -= b;
            }
        }
        return ans; 
    }
};
