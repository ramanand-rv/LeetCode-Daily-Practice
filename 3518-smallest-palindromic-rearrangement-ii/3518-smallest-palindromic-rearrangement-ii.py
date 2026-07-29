class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        n = len(s)
        half = n // 2
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - 97] += 1

        res = [' '] * n
        # middle character
        for i in range(26):
            if freq[i] & 1:
                res[n // 2] = chr(97 + i)
            freq[i] //= 2

        def nCr(n: int, r: int, limit: int) -> int:
            r = min(r, n - r)
            ans = 1
            for i in range(1, r + 1):
                ans = ans * (n - i + 1) // i
                if ans > limit:
                    return limit + 1
            return ans

        def ways(rem: int, f: list, limit: int) -> int:
            total = 1
            for i in range(26):
                total *= nCr(rem, f[i], limit)
                if total > limit:
                    return limit + 1
                rem -= f[i]
            return total

        total = ways(half, freq, k)
        if total < k:
            return ""

        for idx in range(half):
            for i in range(26):
                if freq[i] == 0:
                    continue
                freq[i] -= 1
                possible = ways(half - idx - 1, freq, k)
                if possible >= k:
                    res[idx] = chr(97 + i)
                    break
                else:
                    k -= possible
                    freq[i] += 1

        for i in range(half):
            res[n - 1 - i] = res[i]
        return ''.join(res)