class Solution {
public:
    bool check(vector<bool>& reserved, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (reserved[i]) return false;
        }
        return true;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int m = reservedSeats.size();
        int ans = 0;
        vector<bool> reserved(11, false);
        int prev = 0;
        int l = 0;

        while (l < m) {
            int row = reservedSeats[l][0];
            ans += 2 * (row - prev - 1); // empty rows before this row
            prev = row;

            // Mark all seats reserved in this row
            while (l < m && reservedSeats[l][0] == row) {
                reserved[reservedSeats[l][1]] = true;
                l++;
            }

            bool left  = check(reserved, 2, 5);
            bool mid   = check(reserved, 4, 7);
            bool right = check(reserved, 6, 9);

            if (left && right) ans += 2;
            else if (left || mid || right) ans += 1;

            // reset reserved array for next row
            fill(reserved.begin(), reserved.end(), false);
        }

        // remaining completely empty rows
        ans += 2 * (n - prev);
        return ans;
    }
};