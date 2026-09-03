class Solution:
    def uniformArray(self, nums: list[int]) -> bool:
        mn = float("inf")
        odd_cnt = 0

        for x in nums:
            if x < mn:
                mn = x
            if x & 1:
                odd_cnt += 1

        return (mn % 2 == 1) or (odd_cnt == 0)
