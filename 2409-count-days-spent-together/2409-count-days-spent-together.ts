function countDaysTogether(
    arriveAlice: string,
    leaveAlice: string,
    arriveBob: string,
    leaveBob: string
): number {
    const f = (s: string): number => {
        const m = Number(s[0]) * 10 + Number(s[1]);
        const q = Number(s[3]) * 10 + Number(s[4]);
        return Math.floor((275 * m) / 9) - 2 * Math.floor((m + 9) / 12) + q - 30;
    };

    const a = f(arriveAlice), b = f(leaveAlice);
    const c = f(arriveBob), d = f(leaveBob);

    return Math.max(0, Math.min(b, d) - Math.max(a, c) + 1);
}