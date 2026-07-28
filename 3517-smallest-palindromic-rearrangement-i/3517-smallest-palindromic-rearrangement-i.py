class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        freq = [0] * 26

        # Count frequencies in the first half
        for i in range(n // 2):
            freq[ord(s[i]) - 97] += 1

        arr = list(s)
        j = 0
        for i in range(26):
            while freq[i]:
                arr[j] = arr[n - 1 - j] = chr(97 + i)
                j += 1
                freq[i] -= 1

        return ''.join(arr)