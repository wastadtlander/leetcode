class Solution {
public:
    struct comp {
        bool operator()(auto a, auto b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        } 
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string s : words) freq[s]++;
        priority_queue<pair<string, int>, vector<pair<string,int>>, comp> pq;
        for (auto p : freq) {
            pq.push(make_pair(p.first, p.second));
        }
        vector<string> ret;
        while (k > 0) {
            ret.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ret;
    }  
};
