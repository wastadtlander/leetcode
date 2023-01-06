class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<int> idx(capital.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int& i, int& j) { return capital[i] < capital[j]; });
        priority_queue<int> pq;
        int i = 0;
        while (k > 0) {
            while (i < idx.size() && capital[idx[i]] <= w) pq.push(profits[idx[i++]]);
            if (pq.empty()) return w;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
