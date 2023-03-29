class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int count = 0, i = 0, j = 0;
        while (i < players.size() && j < trainers.size()) {
            while (j < trainers.size() && trainers[j] < players[i]) j++;
            if (j < trainers.size() && players[i++] <= trainers[j++]) count++;
        }
        return count;
    }
};
