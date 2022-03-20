Count the occurrence of all numbers in A and B,
and also the number of domino with two same numbers.
​
Try all possibilities from 1 to 6.
If we can make number i in a whole row,
it should satisfy that countA[i] + countB[i] - same[i] = n
​
Take example of
A = [2,1,2,4,2,2]
B = [5,2,6,2,3,2]
​
countA[2] = 4, as A[0] = A[2] = A[4] = A[5] = 2
countB[2] = 3, as B[1] = B[3] = B[5] = 2
same[2] = 1, as A[5] = B[5] = 2
​
We have countA[2] + countB[2] - same[2] = 6,
so we can make 2 in a whole row.
​
Time O(N), Space O(1)