class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long s2 = st.top();
                st.pop();
                long long s1 = st.top();
                st.pop();
                if (s == "+") {
                    st.push(s1 + s2);
                } else if (s == "-") {
                    st.push(s1 - s2);
                } else if (s == "*") {
                    st.push(s1 * s2);
                } else {
                    st.push(s1 / s2);
                }
            } else {
                st.push((long long)stoi(s));
            }
        }
        return st.top();
    }
};
