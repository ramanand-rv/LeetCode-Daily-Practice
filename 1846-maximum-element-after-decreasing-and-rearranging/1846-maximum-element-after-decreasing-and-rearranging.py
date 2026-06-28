class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        n = len(arr)

        arr.sort()

        t = 1

        for v in arr:
            if v >= t:
                t+=1

        return t-1
'''
        arr[0] = 1
        
        for i in range (1, n):
            if(arr[i] > arr[i-1] +1):
                arr[i] = arr[i-1] +1
        
        return arr[-1]
'''
