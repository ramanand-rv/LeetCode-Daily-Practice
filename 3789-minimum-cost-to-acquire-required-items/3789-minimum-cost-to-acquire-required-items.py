class Solution:
    def minimumCost(
        self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int
    ) -> int:
        # Python handles arbitrarily large integers, no overflow concern
        c1, c2, cb = cost1, cost2, costBoth
        n1, n2 = need1, need2

        # We can cover min(need1, need2) units with a type-3 item
        pairs = min(n1, n2)

        # For each pair, choose the cheaper option: type-3 OR type-1 + type-2
        cost_pairs = pairs * min(cb, c1 + c2)

        # Remaining units of each type after covering the pairs
        rem1 = n1 - pairs
        rem2 = n2 - pairs

        # Cover remaining units with either their specific type OR a type-3 item
        cost_rem = rem1 * min(c1, cb) + rem2 * min(c2, cb)

        return cost_pairs + cost_rem
