class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;

        for (char c : s) {
            umap[c]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b) { 
            return umap[a] > umap[b] || (umap[a] == umap[b] && a < b); 
        });

        return s;
    }
};
