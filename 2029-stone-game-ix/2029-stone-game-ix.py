class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt0 = cnt1 = cnt2 = 0
        for x in stones:
            if x % 3 == 0: cnt0 += 1
            elif x % 3 == 1: cnt1 += 1
            else: cnt2 += 1
        if cnt0 % 2 == 0:
            return cnt1 > 0 and cnt2 > 0
        return abs(cnt1 - cnt2) > 2