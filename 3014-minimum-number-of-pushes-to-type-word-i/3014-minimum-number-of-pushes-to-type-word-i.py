class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0] * 26
        for ch in word:
            freq[ord(ch) - 97] += 1
        freq.sort(reverse=True)

        res = 0
        for i, cnt in enumerate(freq):
            if cnt == 0:
                break
            if i < 8:
                res += cnt
            elif i < 16:
                res += cnt * 2
            elif i < 24:
                res += cnt * 3
            else:
                res += cnt * 4
        return res