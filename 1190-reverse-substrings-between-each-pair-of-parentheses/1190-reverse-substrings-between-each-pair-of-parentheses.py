class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        match = [0] * n
        stack = []
        for i, ch in enumerate(s):
            if ch == "(":
                stack.append(i)
            elif ch == ")":
                j = stack.pop()
                match[i] = j
                match[j] = i

        ans = []
        i, d = 0, 1
        while 0 <= i < n:
            if s[i] in "()":
                i = match[i]
                d = -d
            else:
                ans.append(s[i])
            i += d
        return "".join(ans)
