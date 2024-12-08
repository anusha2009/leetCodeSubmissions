class Solution {
public:
    int maxArea(vector<int>& height) { 
        int max = INT_MIN;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int minHeight = min(height[left], height[right]);
            int container = minHeight * (right-left);
            if(container>max) {
                max = container;
            }
            else if(height[left]>height[right]){
                right--;
            }
            else if(height[left]<=height[right]){
                left++;
            }
            
        }  
        return max;
      
    }
};