#include <vector>
using namespace std;
// :)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            
            // If the middle element is greater than the last element,
            // it means the minimum is in the right half.
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            }
            // If the middle element is less than or equal to the last element,
            // it means the minimum is in the left half, including mid.
            else {
                e = mid;
            }
        }
        
        // 's' will point to the minimum element after the loop ends
        return nums[s];
    }
};