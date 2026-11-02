import random


class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        n = len(nums)
        k = n // 2
        lo, hi = 0, n - 1

        while lo < hi:
            pivot = nums[random.randint(lo, hi)]
            lt, gt, i = lo, hi, lo

            # 3-way partition
            while i <= gt:
                if nums[i] < pivot:
                    nums[lt], nums[i] = nums[i], nums[lt]
                    lt += 1
                    i += 1
                elif nums[i] > pivot:
                    nums[i], nums[gt] = nums[gt], nums[i]
                    gt -= 1
                else:
                    i += 1

            if k < lt:
                hi = lt - 1
            elif k > gt:
                lo = gt + 1
            else:
                break

        median = nums[k]
        return sum(abs(x - median) for x in nums)
