class ProductOfNumbers:
    def __init__(self):
        self.prefix = [1] # Base case for multiplication

    def add(self, num: int) -> None:
        if num == 0:
            # A 0 resets the product history
            self.prefix = [1]
        else:
            # Multiply the new number with the running product
            self.prefix.append(self.prefix[-1] * num)

    def getProduct(self, k: int) -> int:
        n = len(self.prefix)
        # If k is larger than the numbers since the last 0, the window includes a 0
        if k >= n:
            return 0
            
        # Product of last k numbers is total product divided by product before them
        return self.prefix[-1] // self.prefix[-1 - k]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)