class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        depth = 0
        ans = []

        for ch in seq:
            if ch == '(':
                depth += 1
                ans.append(depth % 2)
            else:
                ans.append(depth % 2)
                depth -= 1

        return ans