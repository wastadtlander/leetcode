class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        sort(restaurants.begin(), restaurants.end(), [](auto& r1, auto& r2) {
            return r1[1] > r2[1] || (r1[1] == r2[1] && r1[0] > r2[0]);
        });
        vector<int> ret;
        for (auto& r : restaurants) {
            if ((r[2] == veganFriendly || !veganFriendly) && r[3] <= maxPrice && r[4] <= maxDistance) {
                ret.push_back(r[0]);
            }
        }
        return ret;
    }
};
