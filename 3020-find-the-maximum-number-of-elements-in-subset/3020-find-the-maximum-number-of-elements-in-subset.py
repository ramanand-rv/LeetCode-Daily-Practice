class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        freq = Counter(nums)
        ans = 0;

        for key, val in freq.items():
            curNum = key

            if curNum == 1:
                oneLength = val -1 if val%2 == 0 else val
                ans = max(ans, oneLength)
                continue
            
            curLength = 0

            while curNum in freq and freq[curNum] >=2:
                curLength = curLength + 2
                curNum = curNum * curNum
            
            if curNum in freq and freq[curNum] == 1:
                curLength += 1
            else:
                curLength -= 1
            
            ans = max(ans, curLength)

        return ans