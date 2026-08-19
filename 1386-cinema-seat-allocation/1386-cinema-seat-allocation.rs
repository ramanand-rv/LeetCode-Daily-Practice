impl Solution {
    pub fn max_number_of_families(n: i32, reserved_seats: Vec<Vec<i32>>) -> i32 {
        let mut reserved_seats = reserved_seats;
        reserved_seats.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut ans = 0;
        let mut reserved = [false; 11];
        let mut prev_row = 0;
        let mut i = 0;
        let m = reserved_seats.len();

        while i < m {
            let row = reserved_seats[i][0];
            // empty rows before this one
            ans += 2 * (row - prev_row - 1);
            prev_row = row;

            // mark reserved seats in current row
            while i < m && reserved_seats[i][0] == row {
                reserved[reserved_seats[i][1] as usize] = true;
                i += 1;
            }

            // helper to check a block
            let block_free = |l: usize, r: usize| -> bool {
                (l..=r).all(|seat| !reserved[seat])
            };

            let left  = block_free(2, 5);
            let mid   = block_free(4, 7);
            let right = block_free(6, 9);

            if left && right {
                ans += 2;
            } else if left || mid || right {
                ans += 1;
            }

            // reset reserved array
            reserved = [false; 11];
        }

        // rows after the last reserved row
        ans += 2 * (n - prev_row);
        ans
    }
}