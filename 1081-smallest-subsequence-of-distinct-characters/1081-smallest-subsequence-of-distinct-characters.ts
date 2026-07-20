function smallestSubsequence(s: string): string {
    const last: number[] = new Array(26).fill(-1);
    for (let i = 0; i < s.length; i++) {
        last[s.charCodeAt(i) - 97] = i;
    }

    const inStack: boolean[] = new Array(26).fill(false);
    const stack: string[] = [];

    for (let i = 0; i < s.length; i++) {
        const ch = s[i];
        const idx = ch.charCodeAt(0) - 97;

        if (inStack[idx]) continue;

        while (stack.length > 0 &&
               stack[stack.length - 1] > ch &&
               last[stack[stack.length - 1].charCodeAt(0) - 97] > i) {
            const topIdx = stack[stack.length - 1].charCodeAt(0) - 97;
            inStack[topIdx] = false;
            stack.pop();
        }

        stack.push(ch);
        inStack[idx] = true;
    }

    return stack.join('');
}