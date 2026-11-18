function minChanges(s: string): number {
    let changes = 0;
    // Loop through the string in steps of 2
    for (let i = 0; i < s.length; i += 2) {
        // If the two characters in the pair are different, one change is needed
        if (s[i] !== s[i + 1]) {
            changes++;
        }
    }
    return changes;
}