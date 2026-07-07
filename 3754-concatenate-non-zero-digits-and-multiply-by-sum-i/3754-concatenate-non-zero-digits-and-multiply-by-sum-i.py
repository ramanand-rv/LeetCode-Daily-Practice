class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = 0
        sum_digits = 0
        length = 1

        while n != 0:
            x = (n % 10) * length + x

            if n % 10 != 0:
                length = length * 10

            sum_digits += n % 10

            n = n // 10

        return sum_digits * x
