class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        in_stack = set()
        stack = []

        for i, ch in enumerate(s):
            if ch in in_stack:
                continue

            while stack and stack[-1] > ch and last[stack[-1]] > i:
                in_stack.remove(stack[-1])
                stack.pop()

            stack.append(ch)
            in_stack.add(ch)

        return ''.join(stack)