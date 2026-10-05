function scoreOfParentheses(s: string): number {
    const stack: number[] = [0];
    for (const ch of s) {
        if (ch === '(') {
            stack.push(0);
        } else {
            const v = stack.pop()!;
            const w = stack.pop()!;
            stack.push(w + Math.max(2 * v, 1));
        }
    }
    return stack[0];
}