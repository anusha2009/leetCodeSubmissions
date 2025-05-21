class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        int count = 0;
        int same = 0;
        for(string word : words) {
            string newWord = "";
            newWord = word[1];
            newWord += word[0];
            cout<<newWord<<'\n';
            if(map.find(newWord) != map.end()) {
                count += 4;
                map[newWord]--;
                if(map[newWord] == 0) {
                    map.erase(newWord);
                }
                if(newWord[0] == newWord[1]) {
                    same--;
                }
            } else if(word[0] == word[1]) {
                same++;
                map[word]++;
            } else {
                map[word]++;
            }
        }
        if(same > 0) {
            count += 2;
        }
        return count;
    }
};