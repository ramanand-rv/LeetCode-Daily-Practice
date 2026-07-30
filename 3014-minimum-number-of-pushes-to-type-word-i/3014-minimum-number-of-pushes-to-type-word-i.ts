function minimumPushes(word: string): number {
    const freq = new Array(26).fill(0);
    for (const ch of word) {
        freq[ch.charCodeAt(0) - 97]++;
    }
    freq.sort((a, b) => b - a); // descending

    let res = 0;
    for (let i = 0; i < freq.length; i++) {
        if (freq[i] === 0) break;

        if (i < 8) res += freq[i];

        else if (i < 16) res += freq[i] * 2;

        else if (i < 24) res += freq[i] * 3;
        
        else res += freq[i] * 4;
    }
    return res;
}