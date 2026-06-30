function numberOfSubstrings(s: string): number {
    /*
        const n = s.length;
        let left = 0;
        let cnt = 0;
        let a = 0, b = 0, c = 0;
    
        for (let right = 0; right < n; right++) {
            if (s[right] === 'a') a++;
            else if (s[right] === 'b') b++;
            else c++;
    
            while (a > 0 && b > 0 && c > 0) {
                cnt += (n - right);
    
                if (s[left] === 'a') a--;
                else if (s[left] === 'b') b--;
                else c--;
    
                left++;
            }
        }
    
        return cnt;
    */
    const seen = { a: -1, b: -1, c: -1 };
    let count = 0;

    for (let i = 0; i < s.length; i++) {
        seen[s[i]] = i;

        if (seen.a !== -1 && seen.b !== -1 && seen.c !== -1) {
            const minPos = Math.min(seen.a, seen.b, seen.c);
            count += (minPos + 1);
        }
    }

    return count;

};