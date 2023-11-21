class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        e = encoding;
        i = 0;
        s = 0;
        for (int i = 0; i < encoding.size(); i += 2) s += encoding[i];
    }
    
    int next(int n) {
        if (s - n < 0) {
            s -= n;
            return -1;
        }
        s -= n;
        if (e[i] == 0) i += 2;
        while (n > 0) {
            if (n > e[i]) {
                n -= e[i];
                i += 2;
            } else if (e[i] > n) {
                e[i] -= n;
                n = 0;
            } else if (n == e[i]) {
                n = 0;
                e[i] = 0;
            }
        }
        return e[i + 1];
    }
private:
    vector<int> e;
    int i;
    long long s;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
