class Solution {
public:
    int romanToInt(string s) {
        map<char, int> values{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                              {'C', 100}, {'D', 500}, {'M', 1000}};

        int sum = 0;
        int i = 0;
        while (i < s.length()) {
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            int nextValue = 0;
            // If a next value exists
            if (i + 1 < s.length()) {
                char nextSymbol = s[i + 1];
                nextValue = values[nextSymbol];
            }

            // If this is the subtractive case.
            if (currentValue < nextValue) {
                sum += (nextValue - currentValue);
                i += 2;
            }
            // else this is NOT the subtractive case.
            else {
                sum += currentValue;
                i += 1;
            }
        }
        return sum;
    }
};