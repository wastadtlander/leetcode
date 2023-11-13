class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n);
        for (auto &booking : bookings) {
            seats[booking[0] - 1] += booking[2];
            if (booking[1] < n) seats[booking[1]] -= booking[2];
        }
        for (auto i = 1; i < n; ++i) seats[i] += seats[i - 1]; 
        return seats;
    }
};
