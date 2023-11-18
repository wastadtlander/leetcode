class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (int n : arr) hash[n]++;
        int lucky = -1;
        for (auto& p : hash) 
            if (p.first == p.second)
                lucky = max(lucky, p.first);
        return lucky;
    }
};
