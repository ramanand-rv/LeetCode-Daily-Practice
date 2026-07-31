function minimumPushes(word: string): number {
    const freq = new Array(26).fill(0);
    for (const ch of word) {
        freq[ch.charCodeAt(0) - 97]++;
    }
    freq.sort((a, b) => a - b); // ascending

    let minPushes = 0;
    for (let i = 25, pushCnt = 0; i >= 0; i--) {
        const currIdx = 25 - i;
        if (currIdx % 8 === 0) pushCnt++;
        minPushes += freq[i] * pushCnt;
    }
    return minPushes;
}