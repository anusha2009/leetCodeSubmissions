class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> set;
        int count = 0;
        set.insert(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++) {
            if(set.find(arr[i]+1)!=set.end()) {
                count++;
            }
        }
        return count;
    }
};