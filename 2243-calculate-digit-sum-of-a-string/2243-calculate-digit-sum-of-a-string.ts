function digitSum(s: string, k: number): string {
    // Keep shrinking the string until its length is at most k
    while (s.length > k) {
        let next = "";

        // Process the string in chunks of size k
        for (let i = 0; i < s.length; i += k) {
            let sum = 0;
            // Sum the digits in the current chunk (handles the last short chunk)
            for (let j = i; j < Math.min(s.length, i + k); j++) {
                sum += parseInt(s[j], 10);
            }
            // Append the sum to the next string
            next += sum.toString();
        }

        // Update s for the next round
        s = next;
    }
    return s;
}