struct ComparePair {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    }
};

class FoodRatings {
public:
    unordered_map<string, int> foods_ratings;
    unordered_map<string, string> foods_cuisines;
    unordered_map<string, set<pair<int, string>, ComparePair>> highestRatedFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foods_ratings[foods[i]] = ratings[i];
            foods_cuisines[foods[i]] = cuisines[i];
            highestRatedFoods[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foods_cuisines[food];
        int oldRating = foods_ratings[food];
        foods_ratings[food] = newRating;
        highestRatedFoods[cuisine].erase({oldRating, food});
        highestRatedFoods[cuisine].insert({newRating, food});
    }

    string highestRated(string cuisine) {
        return highestRatedFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */