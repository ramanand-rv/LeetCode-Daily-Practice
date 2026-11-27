function maximumSaleItems(items: number[][], budget: number): number {
    const n = items.length;
    const factors: number[] = [];
    const prices: number[] = [];
    for (let i = 0; i < n; i++) {
        factors.push(items[i][0]);
        prices.push(items[i][1]);
    }

    // Find the cheapest item to fill leftover budget
    const cheapest = Math.min(...prices);

    // best[m] stores max copies for 'm' budget
    const best = new Array(budget + 1).fill(0);
    for (let m = 0; m <= budget; m++) {
        best[m] = Math.floor(m / cheapest); // Baseline
    }

    for (let i = 0; i < n; i++) {
        const factor = factors[i];
        const price = prices[i];
        let gain = 0;
        // Calculate the gain (number of multiples)
        for (const other of factors) {
            if (other % factor === 0) gain++;
        }

        // Only process if gain is better than spending money on the cheapest item
        if (gain > Math.floor(price / cheapest)) {
            // 0/1 Knapsack: iterate backwards to avoid reusing the same first copy
            for (let m = budget; m >= price; m--) {
                best[m] = Math.max(best[m], best[m - price] + gain);
            }
        }
    }

    return best[budget];
}