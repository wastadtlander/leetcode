class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> umap;
        int spaceCount;
        string ret = senders[0];
        for (int i = 0; i < messages.size(); i++) {
            spaceCount = 0;
            for (int j = 0; j < messages[i].size(); j++) {
                if (messages[i][j] == ' ') spaceCount++;
            }
            umap[senders[i]] += spaceCount + 1;
            if (umap[ret] < umap[senders[i]]) ret = senders[i];
            else if (umap[ret] == umap[senders[i]] && senders[i] > ret) ret = senders[i]; 
        }
        return ret;
    }
};
