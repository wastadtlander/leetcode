class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 0) return 0;
        unordered_map<int, int> umap;
        umap[fruits[0]]++;
        int l = 0, r = 1, len = 1;
        while (r < fruits.size()) {
            if (umap.size() <= 2) {
                umap[fruits[r]]++;
                if (umap.size() <= 2) len = max(len, r - l + 1);
                r++;
            }
            if (umap.size() > 2) {
                umap[fruits[l]]--;
                if (umap[fruits[l]] == 0) umap.erase(fruits[l]);
                l++;
            }
            // cout << l << " " << r << endl;
            // for (auto p : umap) {
            //     cout << p.first << " " << p.second << endl;
            // }
            // cout << endl;
        }
        return len;
    }
};
