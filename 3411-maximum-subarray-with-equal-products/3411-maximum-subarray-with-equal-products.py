import math

class Solution:
    def maxLength(self, nums: list[int]) -> int:
        best = 2
        left = 0
        product = 1

        for right in range(len(nums)):
            x = nums[right]
            
            # While the new number shares a factor with the current window's product
            while math.gcd(product, x) > 1:
                # Shrink the window from the left
                product //= nums[left]
                left += 1
                
            # Add the new number to the product
            product *= x
            # Update the maximum length found
            best = max(best, right - left + 1)

        return best