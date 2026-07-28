class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size(), j = 0;
        int freq[26]{};

        // Count frequencies of characters in the first half
        for (int i = 0; i < n >> 1; i++)            
            freq[(s[i] & 31) - 1]++;      // ASCII → char index

        // Fill the string symmetrically with sorted characters
        for (int i = 0; i < 26; i++) {
            while (freq[i]--) {                
                s[j] = 'a' + i;           // left side
                s[n - 1 - j++] = 'a' + i; // right side
            }
        }

        return s;
    }
};