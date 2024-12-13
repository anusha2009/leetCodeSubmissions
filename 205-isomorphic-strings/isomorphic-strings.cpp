class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mappingDictStoT[256] = {0};
        int mappingDictTtoS[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            // Case 1: No mapping exists in either of the dictionaries
            if (mappingDictStoT[c1] == 0 && mappingDictTtoS[c2] == 0) {
                mappingDictStoT[c1] = c2;
                mappingDictTtoS[c2] = c1;
            }

            // Case 2: Either mapping doesn't exist in one of the dictionaries
            // or Mapping exists and it doesn't match in either of the
            // dictionaries or both
            else if (!(mappingDictStoT[c1] == c2 &&
                       mappingDictTtoS[c2] == c1)) {
                return false;
            }
        }

        return true;
    }
};