import bisect


class ProductOfNumbers:
    def __init__(self):
        self.size = 0
        self.zero = -1
        self.where = []
        self.factor = []

    def add(self, num: int) -> None:
        if num == 0:
            # Reset everything since any window including 0 is 0
            self.zero = self.size
            self.where = []
            self.factor = []
        elif num > 1:
            # Only store numbers that affect the product
            self.where.append(self.size)
            self.factor.append(num)
        self.size += 1

    def getProduct(self, k: int) -> int:
        start = self.size - k
        # If the last zero is within or after the start of the window, product is 0
        if self.zero >= start:
            return 0

        # Find the first stored position >= start using binary search
        idx = bisect.bisect_left(self.where, start)

        # Multiply all factors from 'idx' to the end
        ans = 1
        for i in range(idx, len(self.factor)):
            ans *= self.factor[i]
        return ans


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
