class Solution:
    dp = [[] for _ in range(9)]

    @staticmethod
    def computeDP():
        if Solution.dp[0]:
            return
        Solution.dp[0] = [0]
        for i in range(1, 9):
            for j in range(1, i + 1):
                for x in Solution.dp[j - 1]:
                    for y in Solution.dp[i - j]:
                        z = (y << (2 * j)) | (1 << (2 * j - 1)) | (x << 1)
                        Solution.dp[i].append(z)

    @staticmethod
    def to_str(x: int, n: int) -> str:
        ans = []
        for i in range(2 * n):
            if x == 0:
                ans.append("(")
            else:
                ans.append(")" if (x & 1) else "(")
                x >>= 1
        return "".join(ans)

    def generateParenthesis(self, n: int) -> List[str]:
        self.computeDP()
        return [self.to_str(x, n) for x in self.dp[n]]
