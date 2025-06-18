class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> brightnessMap;

        for (auto& light : lights) {
            int start = light[0] - light[1];
            int end = light[0] + light[1];
            brightnessMap[start] += 1;
            brightnessMap[end + 1] -= 1; // end is inclusive
        }

        int maxBrightness = 0, currBrightness = 0;
        int resultPos = INT_MAX;

        for (auto& [pos, delta] : brightnessMap) {
            currBrightness += delta;
            if (currBrightness > maxBrightness) {
                maxBrightness = currBrightness;
                resultPos = pos;
            }
        }

        return resultPos;
    }
};
