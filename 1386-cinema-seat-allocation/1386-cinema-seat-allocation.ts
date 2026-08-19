function maxNumberOfFamilies(n: number, reservedSeats: number[][]): number {
    // Sort by row
    reservedSeats.sort((a, b) => a[0] - b[0]);

    const check = (reserved: boolean[], l: number, r: number): boolean => {
        for (let i = l; i <= r; i++) {
            if (reserved[i]) return false;
        }
        return true;
    };

    let ans = 0;
    const reserved = new Array(11).fill(false);
    let prevRow = 0;
    let i = 0;
    const m = reservedSeats.length;

    while (i < m) {
        const row = reservedSeats[i][0];
        // count empty rows before this one
        ans += 2 * (row - prevRow - 1);
        prevRow = row;

        // mark reserved seats in current row
        while (i < m && reservedSeats[i][0] === row) {
            reserved[reservedSeats[i][1]] = true;
            i++;
        }

        const left  = check(reserved, 2, 5);
        const mid   = check(reserved, 4, 7);
        const right = check(reserved, 6, 9);

        if (left && right) ans += 2;
        else if (left || mid || right) ans += 1;

        // reset for next row
        reserved.fill(false);
    }

    // remaining rows after last reserved row
    ans += 2 * (n - prevRow);
    return ans;
}