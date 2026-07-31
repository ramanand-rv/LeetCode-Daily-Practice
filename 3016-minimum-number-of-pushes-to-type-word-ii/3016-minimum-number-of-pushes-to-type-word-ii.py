class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0] * 26
        for ch in word:
            freq[ord(ch) - 97] += 1
        freq.sort()  # ascending

        min_pushes = 0
        push_cnt = 0
        for i in range(25, -1, -1):
            curr_idx = 25 - i
            if curr_idx % 8 == 0:
                push_cnt += 1
            min_pushes += freq[i] * push_cnt
        return min_pushes