class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_map<string, bool> umap;
        string ret = "";
        for (int i = 0; i < words.size(); i++) {
            cout << words[i] << endl;
            if (words[i].size() == 1) {
                umap[words[i]] = true;
                if (ret == "") {
                    ret = words[i];
                }
            } else if (umap.find(words[i].substr(0, words[i].size() - 1)) != umap.end()) {
                umap[words[i]] = true;
                if (ret.size() < words[i].size()) {
                    ret = words[i];
                }
            }
        }
        return ret;
    }
};
