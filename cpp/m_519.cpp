class Solution {
public:
    Solution(int m, int n) {
        mLocal = m;
        nLocal = n;
        totalFlips = m * n;
        idxs.resize(totalFlips);
        iota(idxs.begin(), idxs.end(), 0);
    }
    
    vector<int> flip() {
        int i = rand() % totalFlips;
        swap(idxs[i], idxs[totalFlips - 1]);
        totalFlips--;
        return {idxs[totalFlips] / nLocal, idxs[totalFlips] % nLocal};
    }
    
    void reset() {
        totalFlips = mLocal * nLocal;
        // idxs.resize(mLocal * nLocal);
        // iota(idxs.begin(), idxs.end(), 0);
    }
private:
    vector<int> idxs;
    int mLocal, nLocal, totalFlips;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
