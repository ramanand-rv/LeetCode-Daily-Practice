class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        seqSum = nums[0];

        for i in range(1, len(nums)):
            if nums[i] == nums[i -1] +1:
                seqSum = seqSum + nums[i]
            else:
                break

        present = [False] * 1276

        for num in nums:
            present[num] = True

        while present[seqSum]:
            seqSum = seqSum + 1

        return seqSum