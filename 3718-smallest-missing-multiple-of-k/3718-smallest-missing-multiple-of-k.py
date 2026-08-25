class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        seen = set()
        for x in nums:
            if x % k == 0:
                seen.add(x // k)
        i = 1
        while i in seen:
            i += 1
        return i * k