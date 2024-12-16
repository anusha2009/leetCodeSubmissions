class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxLength=0;
        int currLength=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            currLength=0;
            int temp = nums[i];
            if(!map[temp-1]){
                while(map[temp]){
                currLength++;
                temp++;
            }
            }
            if(currLength>maxLength){
                maxLength = currLength;
            }
        }
        return maxLength;

        
    }
};