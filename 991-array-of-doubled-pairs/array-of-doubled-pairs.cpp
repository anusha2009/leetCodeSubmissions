class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr)
            freq[num]++;

        // Sort by absolute value to handle negatives properly
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        for (int num : arr) {
            if (freq[num] == 0) continue;

            int target = num * 2;
            if (freq[target] == 0)
                return false;

            freq[num]--;
            freq[target]--;
        }

        return true;
    }
};
