function checkValidString(s: string): boolean {
    let low = 0, high = 0;
    for (const ch of s) {
        if (ch === '(') {
            low++;
            high++;
        } else if (ch === ')') {
            if (low > 0) low--;
            high--;
        } else { // '*'
            if (low > 0) low--;
            high++;
        }
        if (high < 0) return false;
    }
    return low === 0;
}