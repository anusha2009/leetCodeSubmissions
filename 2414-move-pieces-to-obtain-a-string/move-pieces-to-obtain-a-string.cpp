class Solution {
public:
    bool canChange(string start, string target) {
        if(start.size() != target.size()) {
            return false;
        }
        int i = 0;
        int j = 0;
        int countL = 0;
        int countR = 0;
        while(i<start.size() && j<target.size()) {
            if(start[i] == 'L') {
                countL++;
            }
            if(target[i] == 'L') {
                countL--;
            }
            if(start[i] == 'R') {
                countR ++;
            }
            if(target[i] == 'R') {
                countR--;
            }
            if(countL > 0 || countR < 0) {
                return false;
            }
            i++;
            j++;
        }
        string sub1;
        string sub2;
        for(char c : start) {
            if(c!='_') {
                sub1 += c;
            }
        }
        for(char c : target) {
            if(c!='_') {
                sub2 += c;
            }
        }
        return sub1 == sub2;
    }
};