class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorDist = x ^ y;
        int distance = 0;
        while(xorDist != 0) {
            if(xorDist % 2 == 1) {
                distance += 1;
            }
            xorDist = xorDist >> 1;
        }
        return distance;
    }
};