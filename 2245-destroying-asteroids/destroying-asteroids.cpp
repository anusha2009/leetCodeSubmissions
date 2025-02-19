class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<int, vector<int>, greater<int>> minHeap(asteroids.begin(), asteroids.end());
        long long weight = mass;
        while(!minHeap.empty()) {
            int asteroid = minHeap.top();
            minHeap.pop();
            if(asteroid>weight) {
                return false;
            }
            weight += asteroid;
        }
        return true;
    }
};