function minimumCost(cost1: number, cost2: number, costBoth: number, need1: number, need2: number): number {
    // Use BigInt for 64-bit precision
    const c1 = BigInt(cost1), c2 = BigInt(cost2), cb = BigInt(costBoth);
    const n1 = BigInt(need1), n2 = BigInt(need2);

    // We can cover min(need1, need2) units with a type-3 item
    const pairs = n1 < n2 ? n1 : n2;

    // For each pair, choose the cheaper option: type-3 OR type-1 + type-2
    const costPairs = pairs * (cb < c1 + c2 ? cb : c1 + c2);

    // Remaining units of each type after covering the pairs
    const rem1 = n1 - pairs;
    const rem2 = n2 - pairs;

    // Cover remaining units with either their specific type OR a type-3 item
    const costRem = rem1 * (c1 < cb ? c1 : cb) + rem2 * (c2 < cb ? c2 : cb);

    return Number(costPairs + costRem);
}