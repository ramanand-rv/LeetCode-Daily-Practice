class Solution:
    def maximumSaleItems(self, items: list[list[int]], budget: int) -> int:
        factors = [item[0] for item in items]
        prices = [item[1] for item in items]

        # Find the cheapest item to fill leftover budget
        cheapest = min(prices)

        # best[m] stores max copies for 'm' budget
        best = [0] * (budget + 1)
        for m in range(budget + 1):
            best[m] = m // cheapest  # Baseline

        for factor, price in items:
            # Calculate the gain (number of multiples)
            gain = sum(1 for other in factors if other % factor == 0)

            # Only process if gain is better than spending money on the cheapest item
            if gain > price // cheapest:
                # 0/1 Knapsack: iterate backwards to avoid reusing the same first copy
                for m in range(budget, price - 1, -1):
                    best[m] = max(best[m], best[m - price] + gain)

        return best[budget]
