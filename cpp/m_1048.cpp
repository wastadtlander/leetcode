class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string s1, string s2) {
            return s1.size() < s2.size();
        });
        unordered_map<string, int> umap;
        int ret = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string sub = words[i].substr(0, j) + words[i].substr(j + 1);
                umap[words[i]] = max(umap[words[i]], umap.find(sub) == umap.end() ? 1 : umap[sub] + 1);
            }
            ret = max(ret, umap[words[i]]);
        }
        return ret;
    } 
};
