class Solution {
public:
    string reorganizeString(string s) {
        // Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Build a max-heap based on character frequency
    priority_queue<pair<int, char>> maxHeap;
    for (auto& [character, count] : freq) {
        // If any character's frequency is greater than (n + 1) / 2, return ""
        if (count > (s.length() + 1) / 2) return "";
        maxHeap.push({count, character});
    }

    // Step 3: Reorganize the string
    string result;
    while (maxHeap.size() > 1) {
        // Pop two most frequent characters
        auto [count1, char1] = maxHeap.top();
        maxHeap.pop();
        auto [count2, char2] = maxHeap.top();
        maxHeap.pop();

        // Append these characters to the result
        result += char1;
        result += char2;

        // Decrease their frequencies and push back if they are still needed
        if (--count1 > 0) maxHeap.push({count1, char1});
        if (--count2 > 0) maxHeap.push({count2, char2});
    }

    // If there's one character left, add it if its frequency is 1
    if (!maxHeap.empty()) {
        auto [count, char1] = maxHeap.top();
        if (count > 1) return "";  // Not possible to rearrange
        result += char1;
    }

    return result;

    }
};