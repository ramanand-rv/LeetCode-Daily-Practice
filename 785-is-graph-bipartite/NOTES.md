![](https://assets.leetcode.com/users/images/335dc44e-965c-4779-9757-40ffad537f5a_1613330997.6753454.png)
A. Traverse each node of the graph and try to assign a color to them such that alternating nodes are of same color.
B. If at any step, the child node color matches with the parent node color, then the graph is not bipartite.
C. If no B found, then the graph is bipartite. So, return true at the end.
D. Here, the two colors are represented by 0 and 1.