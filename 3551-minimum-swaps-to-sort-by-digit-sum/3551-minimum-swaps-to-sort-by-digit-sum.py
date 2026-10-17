import numpy as np

r = np.arange(100000)
DS = sum(r // 10**k % 10 for k in range(5))  # digit sums of 0..99999, built once


class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        a = np.array(nums, dtype=np.int64)
        key = (
            DS[a % 100000] + DS[a // 100000]
        ) << 30 | a  # digit sum first, then the value
        home = (
            key.argsort().argsort().tolist()
        )  # where the value at each position must go

        swaps = 0
        for i in range(len(home)):
            while (
                home[i] != i
            ):  # send the value at i home, take that spot's value in exchange
                j = home[i]
                home[i], home[j] = home[j], home[i]
                swaps += 1
        return swaps
