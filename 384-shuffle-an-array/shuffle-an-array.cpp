class Solution {
private:
    vector<int> array;
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        array = nums;
        original = nums;
        //srand(time(NULL)); // Seed random once
    }

    vector<int> reset() {
        array = original;
        return original;
    }

    vector<int> shuffle() {
        for (int i = 0; i < array.size(); ++i) {
            int j = randRange(i, array.size()); // pick index from i to end
            swap(array[i], array[j]);
        }
        return array;
    }

private:
    int randRange(int min, int max) {
        return rand() % (max - min) + min; // returns int in [min, max)
    }
};
