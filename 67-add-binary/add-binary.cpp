class Solution {
 public:
  string addBinary(string s1, string s2) {
    int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
    string str = "";
    
    // Step 1: Process both strings from right to left
    while (i >= 0 && j >= 0) {
        int sum = (s1[i] - '0') + (s2[j] - '0') + carry;
        carry = sum / 2;
        int digit = sum % 2;
        str += to_string(digit);
        i--;
        j--;
    }
    
    // Step 2: Process remaining digits of s1
    while (i >= 0) {
        int sum = (s1[i] - '0') + carry;
        carry = sum / 2;
        int digit = sum % 2;
        str += to_string(digit);
        i--;
    }
    
    // Step 3: Process remaining digits of s2
    while (j >= 0) {
        int sum = (s2[j] - '0') + carry;
        carry = sum / 2;
        int digit = sum % 2;
        str += to_string(digit);
        j--;
    }
    
    // Step 4: Add any final carry
    if (carry > 0) {
        str += to_string(carry);
    }
    
    // Step 5: Reverse the result before returning
    reverse(str.begin(), str.end());
    return str;
  }
};