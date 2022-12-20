class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> v(rooms.size(), 0);
        q.push(0);
        while (!q.empty()) {
            v[q.front()] = 1;
            for (int n : rooms[q.front()]) {
                if (v[n] == 0) {
                    q.push(n);
                }
            }
            q.pop();
        }
        return find(v.begin(), v.end(), 0) == v.end();
    }
};
