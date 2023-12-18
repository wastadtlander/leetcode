class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineToRating[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
            foodToRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        cuisineToRating[cuisine].erase(make_pair(-foodToRating[food], food));
        cuisineToRating[cuisine].insert(make_pair(-newRating, food));
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToRating[cuisine].begin()->second;
    }
private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineToRating;
    unordered_map<string, int> foodToRating;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
