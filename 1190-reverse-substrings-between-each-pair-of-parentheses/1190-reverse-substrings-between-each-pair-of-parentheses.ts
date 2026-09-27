function reverseParentheses(s: string): string {
    const n = s.length;
    const match = new Array(n).fill(0);
    const stack: number[] = [];

    for (let i = 0; i < n; i++) {
        if (s[i] === '(') stack.push(i);
        else if (s[i] === ')') {
            const j = stack.pop()!;
            match[i] = j;
            match[j] = i;
        }
    }

    let ans = '';
    let i = 0, dir = 1;
    while (i >= 0 && i < n) {
        if (s[i] === '(' || s[i] === ')') {
            i = match[i];
            dir = -dir;
        } else {
            ans += s[i];
        }
        i += dir;
    }
    return ans;
}