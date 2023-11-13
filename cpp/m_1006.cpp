class Solution {
public:
    int clumsy(int n) {
        queue<int> q;
        for (auto i = n; i > 0; i -= 4) {
            if (i - 4 >= 0) q.push(i * (i - 1) / (i - 2));
            else if (i - 3 >= 0) q.push(i * (i - 1));
            else q.push(i);
        }
        auto t = q.front();
        q.pop();
        for (int i = n - 3; i > 0; i -= 4) {
            if (i >= 1) t += i;
            if (!q.empty()) {
                t -= q.front();
                q.pop();
            }
        }
        return t;
    }
};
