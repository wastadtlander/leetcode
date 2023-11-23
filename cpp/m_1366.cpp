class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ret = votes[0];
        vector<vector<int>> winMap(26, vector<int>(26));
        for (string s : votes) {
            for (int i = 0; i < s.size(); ++i) {
                winMap[s[i] - 'A'][i]++;
            }
        }
        sort(ret.begin(), ret.end(), [winMap](char a, char b) {
            bool winner = a < b;
            for (int i = 0; i < winMap.size(); ++i) {
                if (winMap[a - 'A'][i] == winMap[b - 'A'][i]) continue;
                return winMap[a - 'A'][i] > winMap[b - 'A'][i];
            }
            return winner;
        });
        return ret;
    }
};
