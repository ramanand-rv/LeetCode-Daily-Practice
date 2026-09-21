class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        arr = [x % k for x in nums]
        res = [0] * k

        for req in range(k):
            dp = [[[-1] * k for _ in range(k + 1)] for _ in range(n)]

            def solve(i: int, prevProd: int) -> int:
                if i >= n:
                    return 0
                if dp[i][prevProd][req] != -1:
                    return dp[i][prevProd][req]

                skip = 0
                take = 0

                if prevProd == k:
                    skip = solve(i + 1, k)

                curProd = arr[i] if prevProd == k else (prevProd * arr[i]) % k
                if curProd == req:
                    take += 1
                take += solve(i + 1, curProd)

                total = skip + take
                dp[i][prevProd][req] = total
                return total

            res[req] = solve(0, k)

        return res