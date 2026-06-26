import bisect

class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tails = []
        for x in nums:
            pos = bisect.bisect_left(tails, x)
            if(pos == len(tails)):
                tails.append(x)
            else:
                tails[pos] = x
        
        return len(tails)