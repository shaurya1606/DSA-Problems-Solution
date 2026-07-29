class FoodRatings {
private:
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;

    // cuisine -> {(-rating, food)}
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        for (int i = 0; i < foods.size(); i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {

        string cuisine = foodInfo[food].first;
        int oldRating = foodInfo[food].second;

        // Remove old entry
        cuisineFoods[cuisine].erase({-oldRating, food});

        // Update rating
        foodInfo[food].second = newRating;

        // Insert new entry
        cuisineFoods[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {

        return cuisineFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */