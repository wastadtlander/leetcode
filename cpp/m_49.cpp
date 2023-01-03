class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> umap;
        for (string s : strs) {
            string temp = s;
            sort(s.begin(), s.end());
            umap[s].push_back(temp);
        }
        for (pair p : umap) {
            vector<string> temp;
            for (string s : p.second) {
                temp.push_back(s);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
