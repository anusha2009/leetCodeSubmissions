class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> hashmap;

        for (int num : nums2) {
            while (!stack.empty() && num > stack.top()) {
                hashmap[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }

        while (!stack.empty()) {
            hashmap[stack.top()] = -1;
            stack.pop();
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(hashmap[num]);
        }

        return ans;
    }
};