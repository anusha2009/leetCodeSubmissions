class Solution {
public:
    int mySqrt(int x) {
        if(x==0) {
            return 0;
        } 
        long left = 1;
        long right = x;
        while(left<=right) {
            long mid = (left+right)/2;
            if((mid*mid) ==x) {
                return mid;
            } else if((mid*mid)<x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }
        return right;
    }
};