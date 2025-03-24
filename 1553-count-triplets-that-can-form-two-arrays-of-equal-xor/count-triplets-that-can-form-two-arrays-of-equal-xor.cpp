class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> countMap;  // prefix xor value -> count of times seen
        unordered_map<int, int> totalMap;  // prefix xor value -> total indices sum

        int prefixXor = 0, result = 0;
        countMap[0] = 1;
        totalMap[0] = 0;

        for (int i = 0; i < n; ++i) {
            prefixXor ^= arr[i];

            if (countMap.count(prefixXor)) {
                // countMap[prefixXor] gives how many times we saw this prefixXor before
                // totalMap[prefixXor] gives the sum of indices of those occurrences
                result += countMap[prefixXor] * i - totalMap[prefixXor];
            }

            countMap[prefixXor]++;
            totalMap[prefixXor] += i + 1;
        }

        return result;
}
};