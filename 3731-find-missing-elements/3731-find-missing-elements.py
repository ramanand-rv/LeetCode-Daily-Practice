class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        present = [False] * 101
        minVal, maxVal = float('inf'), float('-inf')

        for ele in nums:
            minVal = min(minVal, ele)
            maxVal = max(maxVal, ele)
            present[ele] = True

        return [i for i in range(minVal, maxVal + 1) if not present[i]]