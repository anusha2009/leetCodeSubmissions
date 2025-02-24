class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int left = INT_MAX;
        int right = 0;
        for(int day : bloomDay) {
            left = min(day, left);
        }
        for(int day : bloomDay) {
            right = max(day, right);
        }
        while(left<=right) {
            int mid = left + (right - left)/2;
            if(check(mid, bloomDay, m, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(int mid, vector<int>& bloomDay, int m, int k) {
        int bouquet = 0;
        int flower = 0;
        for(int day : bloomDay) {
            if(day>mid) {
                flower = 0;
                continue;
            } else if(day<=mid && flower<k) {
                flower++;
                if(flower == k) {
                    bouquet++;
                    flower = 0;
                }
            }
        }
        return bouquet >= m;
    }
};