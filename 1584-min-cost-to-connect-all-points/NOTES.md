One of the problems with using a regular heap with Prim's in a densely populated graph is that the heap would keep storing the no longer relevant elements and thus for a 1000 node graph, we would have to do approximately 10^6 pops on the Heap. Effectively a O(n^2logn).
A simpler approach would be to use the trimming approach on heap. High level algo:
​
1. Keep a vector minDist(C++) for each node to represent minimum distance to the current Spanning Tree.
​
2. Initialize minDist[0] to INT_MAX and minDist[i] to distance from Node 0. (Start from Node 0 and build Spanning Tree).
​
3. Keep building the spanning tree by picking the min of all the minDist (O(n)). If this node was 'v', mark minDist[v] = INT_MAX. (Add Node 'v' to Spanning Tree)
​
4. When a new node 'v' is picked, update minDist by minDist[i] = min (minDist[i], distance[v,i]). (Update the cost of the current Min Spanning Tree)
​
Complexity would be O(n^2) and space of O(n).