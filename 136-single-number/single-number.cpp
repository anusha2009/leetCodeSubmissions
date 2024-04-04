class Solution {
public:
    int singleNumber(vector<int>& a) {
        //xor all numbers, the left over number would be the non repeated one
     // since the equl numbers cancel out each others bits
     int num = 0;
     for (int i = 0; i < a.size(); ++i) {
        
         num ^= a[i];
     }
     return num;
    }
};