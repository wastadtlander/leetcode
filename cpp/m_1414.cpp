class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<long long> fib;
        fib.push_back(1);
        fib.push_back(1);
        while (fib.back() <= k) {
            int n = fib.size();
            fib.push_back(fib[n - 1] + fib[n - 2]);
        }
        int sum = 0, count = 0, i = fib.size() - 1;
        while (sum != k) {
            if (sum + fib[i] <= k) {
                sum += fib[i];
                count++;
            } else {
                i--;
            }
        }
        return count;
    }
};
