**We just need to group all pairs using DSU. And after grouping them together we will have connected componend (pairs) together. Which means we have to sort each connected component because we need smallest lexical string. **
​
***Suppose The Input Is ***
s = "dcab", pairs = [[0,3],[1,2]]
​
Then 0---3 is forming one group let's say 0
1--2 is forming one group let's say 1
​
So, we have two connected component
index-> 0 1 2 3
Now "d c a b" sort the connected component i.e indexes sort(0,3) and (1,2)
"b c a d" (0,3 sorted)
"b a c d" (1,3 sorted)
​
"b a c d"   (answer)
***Suppose The Input Is
s = "dcab", pairs = [[0,3],[1,2],[0,2]] ***
​
Then 0---3 is forming one group let's say 0
1--2 is forming one group let's say 1
again 0--2 is forming group since 0 and 2 was already in group , hence everyone is under same group (DSU)
**0-1-2-3 is under same group . Hence we have only 1 connected component **.
​
So, we have one connected component
index-> 0 1 2 3
Now "d c a b" sort the connected component i.e sort indexes (0,1,2,3)
"a b c d" sorted (0,1,2,3)
​
"a b c d" (answer)