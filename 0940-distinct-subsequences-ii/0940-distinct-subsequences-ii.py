class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        end_with = [0] * 26
        total = 0

        for ch in s:
            idx = ord(ch) - 97
            new = (1 + total - end_with[idx]) % MOD
            total = (total + new) % MOD
            end_with[idx] = (end_with[idx] + new) % MOD

        return total
