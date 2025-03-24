class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int great = 0;
        vector<bool> result;
        for(int candy : candies) {
            great = max(candy, great);
        }
        for(int candy : candies) {
            if(candy + extraCandies >= great) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};