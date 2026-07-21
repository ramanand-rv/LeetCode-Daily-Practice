class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        n = len(s)
        prev_zero = 0
        curr_zero = 0
        total_ones = 0
        best = 0
        i = 0

        while i < n:
            if s[i] == '0':
                prev_zero += 1
                i += 1
            else:
                while i < n and s[i] == '1':
                    total_ones += 1
                    i += 1
                while i < n and s[i] == '0':
                    curr_zero += 1
                    i += 1
                if prev_zero and curr_zero:
                    best = max(best, prev_zero + curr_zero)
                prev_zero = curr_zero
                curr_zero = 0

        return total_ones + best