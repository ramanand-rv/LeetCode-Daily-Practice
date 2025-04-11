class Solution {
    public:
        int countSymmetricRec(const string &numStr, int idx, int n, int tight, int hasNonZero, int isSecondHalf, int rem, int diff, int FirstHalfSum, int diffFromLeft,
                              vector<vector<vector<vector<vector<vector<int>>>>>> &dp) {
            
            // Base Case: When we have processed all digits,
            // check if the number is valid (i.e., non-zero-started and symmetric).
            if (idx == n) 
                return (hasNonZero && diff == 0 && rem == 0) ? 1 : 0;
            
            // Get the memoized result for the current state.
            // We add offsets (FirstHalfSum and diffFromLeft) to shift potential negative values to positive indices.
            int &dpVal = dp[idx][tight][hasNonZero][isSecondHalf][rem + FirstHalfSum][diff + diffFromLeft];
            if (dpVal != -1)
                return dpVal;
            
            // Determine the maximum digit available at this index:
            // If 'tight' is true, the maximum is bound by the current digit in numStr.
            // Otherwise, we can choose any digit from 0 to 9.
            int maxDigit = (tight ? numStr[idx] - '0' : 9);
            int result = 0;
            
            // Try every possible digit from 0 to maxDigit at this position.
            for (int digit = 0; digit <= maxDigit; digit++) {
                // Update hasNonZero: becomes true if already true, or if the chosen digit is nonzero.
                int newHasNonZero = hasNonZero || (digit != 0);
                // Start with current balance and difference values.
                int newRem = rem;
                int newDiff = diff;
                
                // Update the running difference and balance counter based on the current half.
                if (isSecondHalf) {
                    // In the second half, subtract the digit from the running difference.
                    newDiff -= digit;
                    // Also, decrease the balance counter if a nonzero digit has been set.
                    if (newHasNonZero)
                        newRem -= 1;
                } else {
                    // In the first half, add the digit to the running difference.
                    newDiff += digit;
                    // Increase the balance counter if we've started the number.
                    if (newHasNonZero)
                        newRem += 1;
                }
                
                // Determine if the next state remains tight:
                // It's still tight if we chose the maximum allowed digit.
                int newTight = (tight && (digit == maxDigit)) ? 1 : 0;
                
                // Continue building the number with the chosen digit.
                result += countSymmetricRec(numStr, idx + 1, n, newTight, newHasNonZero, isSecondHalf, newRem, newDiff,
                                            FirstHalfSum, diffFromLeft, dp);
                
                // Branch into processing the second half if we are currently in the first half and the number has started.
                if (newHasNonZero && !isSecondHalf) {
                    result += countSymmetricRec(numStr, idx + 1, n, newTight, newHasNonZero, 1, newRem, newDiff,
                                                FirstHalfSum, diffFromLeft, dp);
                }
            }
            
            // Save the computed result for this state and return.
            dpVal = result;
            return result;
        }
        
        // Counts all symmetric numbers up to 'num'.
        int countUpTo(int num) {
            string numStr = to_string(num);
            int n = numStr.size();
            
            // Offsets used to ensure dp table indices are always non-negative.
            int FirstHalfSum = n;       // Shifts 'rem' range.
            int diffFromLeft = 9 * n;     // Shifts 'diff' range.
            
            // Parameters explained in solution
            vector<vector<vector<vector<vector<vector<int>>>>>> dp(
                n + 1, vector<vector<vector<vector<vector<int>>>>>(2,
                vector<vector<vector<vector<int>>>>(2,
                vector<vector<vector<int>>>(2,
                vector<vector<int>>(2 * n + 1, vector<int>(18 * n + 1, -1))))
            ));
            
            // Start recursion from the first digit, with a tight bound (tight = 1),
            // no nonzero digit encountered yet (hasNonZero = 0), and in first half mode (isSecondHalf = 0).
            return countSymmetricRec(numStr, 0, n, 1, 0, 0, 0, 0, FirstHalfSum, diffFromLeft, dp);
        }
        
        // To count symmetric integers within the inclusive range [low, high].
        int countSymmetricIntegers(int low, int high) {
            // Count symmetric numbers up to 'high' and subtract those up to 'low - 1'.
            return countUpTo(high) - countUpTo(low - 1);
        }
    };