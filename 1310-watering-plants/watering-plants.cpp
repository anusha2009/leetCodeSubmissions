class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step = 0;
        int currCapacity = capacity;
        for(int i = 0; i<plants.size(); i++) {
            step++;
            cout<<step<<'\n';
            currCapacity = currCapacity - plants[i];
            if(i!=plants.size()-1 && plants[i+1]>currCapacity) {
                step = step + i + 1 + i + 1;
                cout<<step<<i<<'\n';
                currCapacity = capacity;
            }
        }
        return step;
    }
};