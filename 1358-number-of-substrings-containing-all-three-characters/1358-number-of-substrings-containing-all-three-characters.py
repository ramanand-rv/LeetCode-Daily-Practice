class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        left = 0
        cnt = 0
        a = b = c = 0

        for right in range(n):
            if s[right] == 'a':
                a += 1
            elif s[right] == 'b':
                b += 1
            else:
                c += 1

            while a > 0 and b > 0 and c > 0:
                cnt += (n - right)

                if s[left] == 'a':
                    a -= 1
                elif s[left] == 'b':
                    b -= 1
                else:
                    c -= 1
                
                left += 1

        return cnt