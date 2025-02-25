#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0;
        double right = stations.back() - stations.front(); // maximum gap possible
        double eps = 1e-6;
        
        // Binary search for the smallest mid such that the extra stations needed is <= k.
        while(right - left > eps) {
            double mid = left + (right - left) / 2.0;
            if(check(mid, stations, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
    
    bool check(double mid, vector<int>& stations, int k) {
        int used = 0;
        for(int i = 0; i < stations.size()-1; i++) {
            int gap = stations[i+1] - stations[i];
            // extra stations needed = ceil(gap / mid) - 1
            int extra = (int)ceil((double)gap / mid) - 1;
            used += extra;
        }
        return used <= k;
    }
};
