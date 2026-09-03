class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = INT_MAX;
        int oddCnt = 0;

        for (int x : nums) {
            if (x < mn)
                mn = x;
            if (x & 1)
                oddCnt++; // check parity using bitwise AND
        }

        // Valid if minimum is odd OR there are no odd numbers
        return (mn & 1) || (oddCnt == 0);
    }
};