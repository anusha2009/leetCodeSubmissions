/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int celeb = 0;
        for(int i = 0; i<n; i++) {
            if(knows(celeb, i)) {
                celeb = i;
            }
        }

        if(isCeleb(celeb, n)) {
            return celeb;
        }
        return -1;
    }

    int isCeleb(int celeb, int n) {
        for(int i = 0; i<n; i++) {
            if(celeb==i) continue;
            if(knows(celeb, i) || !knows(i, celeb)) {
                return false;
            }
        }
        return true;
    }
};