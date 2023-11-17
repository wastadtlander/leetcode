class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        auto comp = [&heights](int i, int j) { return heights[i] > heights[j]; };
        vector<int> idx(names.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), comp);
        vector<string> res(names.size());
        for (int i = 0; i < names.size(); i++) res[i] = names[idx[i]];
        return res;
    }
};
