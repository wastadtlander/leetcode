class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> umap;
        for (int n : tasks) umap[n]++;
        int rounds = 0;
        for (pair p : umap) {
            while (p.second != 0) {
                if (p.second < 2) {
                    return -1;
                } else if (p.second == 2 || p.second - 2 == 2) {
                    p.second -= 2;
                } else if (p.second >= 3) {
                    p.second -= 3;
                }
                rounds++;
            }       
        }
        return rounds;
    }
};
