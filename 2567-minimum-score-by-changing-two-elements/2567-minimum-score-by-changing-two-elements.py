class Solution:
    def minimizeSum(self, nums: list[int]) -> int:
        s0 = s1 = s2 = float('inf')
        l0 = l1 = l2 = float('-inf')

        for x in nums:
            # Update 3 smallest
            if x < s0:
                s2, s1, s0 = s1, s0, x
            elif x < s1:
                s2, s1 = s1, x
            elif x < s2:
                s2 = x

            # Update 3 largest
            if x > l0:
                l2, l1, l0 = l1, l0, x
            elif x > l1:
                l2, l1 = l1, x
            elif x > l2:
                l2 = x

        # Three ways to remove two elements:
        # 1. Remove two largest -> range = l2 - s0
        # 2. Remove two smallest -> range = l0 - s2
        # 3. Remove one smallest and one largest -> range = l1 - s1
        return min(l0 - s2, l2 - s0, l1 - s1)