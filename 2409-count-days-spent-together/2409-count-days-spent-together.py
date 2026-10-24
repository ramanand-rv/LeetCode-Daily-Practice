class Solution:
    def countDaysTogether(
        self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str
    ) -> int:
        def f(s: str) -> int:
            m = int(s[:2])
            q = int(s[3:])
            return (275 * m) // 9 - 2 * ((m + 9) // 12) + q - 30

        a, b = f(arriveAlice), f(leaveAlice)
        c, d = f(arriveBob), f(leaveBob)

        return max(0, min(b, d) - max(a, c) + 1)
