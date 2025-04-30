class Solution {
public:
    double func(vector<vector<int>>& vec, double mid) {
        double ans = 0;
        for (auto& i : vec) {
            double y = i[1];
            double l = i[2];

            if ((y + l) <= mid) {
                ans += l * l;
            } else if (y < mid) {
                double h = mid - y;
                ans += l * h;
            }
        }
        return ans;
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // Use strict inequality for consistency
    }

    double separateSquares(vector<vector<int>>& vec) {
        int n = vec.size();
        if (n == 0) return 0; // Edge case: no squares

        // sort(vec.begin(), vec.end(), comp);

        double totalArea = 0;
        double maxY = 0;
        for (auto& i : vec) {
            double l = i[2];
            totalArea += l * l;
            maxY = max(maxY, (double)(i[1] + l)); // Update the maximum y-coordinate
        }

        double low = 0, high = maxY;
        int iterations = 100; // Fixed number of iterations for binary search
        while (iterations--) {
            double mid = low + (high - low) / 2;
            double area = func(vec, mid);
            if (area < totalArea / 2) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};