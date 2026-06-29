function numOfStrings(patterns: string[], word: string): number {
    let substring = 0;

    for (const s of patterns) {
        if(word.includes(s)){
            substring++;
        }
    }

    return substring;
    
};