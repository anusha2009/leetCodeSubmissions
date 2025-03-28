class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = arr[i];
                int b = arr[j];
                int length = 2;

                // Try to build the Fibonacci-like sequence
                while (numSet.count(a + b)) {
                    int next = a + b;
                    a = b;
                    b = next;
                    length++;
                }

                if (length >= 3) {
                    maxLen = max(maxLen, length);
                }
            }
        }

        return maxLen;
    }
};
