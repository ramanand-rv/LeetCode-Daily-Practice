class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr1.sort()
        arr2.sort()

        ans = 0
        j = 0

        for x in arr1:
            # Advance j to the first element in arr2 that is >= x - d
            while j < len(arr2) and arr2[j] < x - d:
                j += 1

            # If no such element exists, or it's strictly greater than x + d, x is valid
            if j == len(arr2) or arr2[j] > x + d:
                ans += 1

        return ans
