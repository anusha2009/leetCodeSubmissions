/*class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies.back();
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
};*/

class Solution {
public:
    // Function to calculate sum of first n natural numbers
    int count(int n) { return (n * (n + 1)) / 2; }
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) {
            return ratings.size();
        }
        int candies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        for (int i = 1; i < ratings.size(); i++) {
            int newSlope = (ratings[i] > ratings[i - 1])
                               ? 1
                               : (ratings[i] < ratings[i - 1] ? -1 : 0);
            // slope is changing from uphill to flat or downhill
            // or from downhill to flat or uphill
            if ((oldSlope > 0 && newSlope == 0) ||
                (oldSlope < 0 && newSlope >= 0)) {
                candies += count(up) + count(down) + max(up, down);
                up = 0;
                down = 0;
            }
            // slope is uphill
            if (newSlope > 0) {
                up++;
            }
            // slope is downhill
            else if (newSlope < 0) {
                down++;
            }
            // slope is flat
            else {
                candies++;
            }
            oldSlope = newSlope;
        }
        candies += count(up) + count(down) + max(up, down) + 1;
        return candies;
    }
};