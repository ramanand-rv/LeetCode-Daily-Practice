#include <cmath>

class Solution {
public:
    bool canAliceWin(int n) {
        // All 10 moves would require 55 stones (10+9+...+1)
        int missing = 55 - n;

        // Find the number of unplayed moves (the smallest j such that 1+2+...+j
        // >= missing) This simplifies to j = round(sqrt(2 * missing))
        int unplayed = std::round(std::sqrt(2.0 * missing));

        // If the number of unplayed moves is odd, the number of played moves is
        // also odd (10 - odd = odd) Odd number of moves means Alice made the
        // last move and wins
        return unplayed % 2 == 1;
    }
};