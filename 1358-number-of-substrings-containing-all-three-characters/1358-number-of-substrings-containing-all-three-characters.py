class Solution:
    def numberOfSubstrings(self, s: str) -> int:

        # n = len(s)
        # left = 0
        # cnt = 0
        # a = b = c = 0

        # for right in range(n):
        #     if s[right] == "a":
        #         a += 1
        #     elif s[right] == "b":
        #         b += 1
        #     else:
        #         c += 1

        #     while a > 0 and b > 0 and c > 0:
        #         cnt += n - right

        #         if s[left] == "a":
        #             a -= 1
        #         elif s[left] == "b":
        #             b -= 1
        #         else:
        #             c -= 1

        #         left += 1

        # return cnt

        seen = {'a': -1, 'b': -1, 'c': -1}
        count = 0
        
        for i, ch in enumerate(s):
            seen[ch] = i
            
            if seen['a'] != -1 and seen['b'] != -1 and seen['c'] != -1:
                minPos = min(seen.values())
                count += (minPos + 1)
        
        return count
