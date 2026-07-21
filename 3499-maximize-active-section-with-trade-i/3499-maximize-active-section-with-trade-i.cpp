class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int prevZero = 0, currZero = 0;
        int totalOnes = 0;
        int best = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '0') {
                prevZero++;
                i++;
            } else {
                while (i < n && s[i] == '1') {
                    totalOnes++;
                    i++;
                }

                while (i < n && s[i] == '0') {
                    currZero++;
                    i++;
                }

                if (prevZero && currZero)
                    best = max(best, prevZero + currZero);

                prevZero = currZero;
                currZero = 0;
            }
        }

        return totalOnes + best;
    }
};