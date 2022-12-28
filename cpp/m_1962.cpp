class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int n : piles) pq.push(n);
        while (k > 0) {
            int n = pq.top();
            pq.pop();
            n -= floor(n / 2);
            pq.push(n);
            k--;
        }
        int minSum = 0;
        while (!pq.empty()) {
            minSum += pq.top();
            pq.pop();
        }
        return minSum;
    }
};
