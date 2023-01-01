class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> umap1;
        unordered_map<string, int> umap2;
        int i = 0;
        stringstream ss(s);
        string w;
        while (ss >> w) {
            if (i == pattern.size() || umap1[pattern[i]] != umap2[w]) {
                return false;
            }

            umap1[pattern[i]] = i + 1;
            umap2[w] = i + 1;
            i++;
        }
        return i == pattern.size();
    }
};
