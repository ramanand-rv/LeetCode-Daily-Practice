class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        // Loop through the string in steps of 2
        for (int i = 0; i < s.length(); i += 2) {
            // If the two characters in the pair are different, one change is
            // needed
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        return changes;
    }
};