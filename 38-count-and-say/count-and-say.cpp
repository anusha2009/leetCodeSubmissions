class Solution {
public:
    string countAndSay(int n) {
        vector<string> result(n);
        result[0] = "1";
        for(int i = 1; i<n; i++) {
            result[i] = count(result[i-1]);
        }
        return result[n-1];

    }
    string count(string n) {
    string res = "";
    int i = 0;
    while (i < n.size()) {
        char c = n[i];
        int count = 0;
        while (i < n.size() && n[i] == c) {
            count++;
            i++;
        }
        res += to_string(count) + c;
    }
    return res;
}
};