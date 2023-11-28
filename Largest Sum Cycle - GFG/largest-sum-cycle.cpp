//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  void dfs(int node, vector<bool>&visited, 
  vector<bool>& inRec, vector<int>& edge){
    visited[node] = true;
    inRec[node] = true;
    if(edge[node] != -1){
      int adjNode = edge[node];
      if(!visited[adjNode]) dfs(adjNode, visited, inRec, edge);
      else if(inRec[adjNode]){
        long long sum=0;
        
        // Won't give sum of cycle nodes
        // for(int i=0;i<inRec.size();i++){
        //   if(inRec[i]) sum += i;
        // }
        int cur = adjNode;
        do{
            sum+= cur;
            cur = edge[cur];
        } while(cur != adjNode);
        largestSum = max(largestSum, sum);
      }
    }
    inRec[node] = false;
  }
  
  
  public:
  long long largestSum = -1;
  long long largestSumCycle(int N, vector<int> edge)
  {
      vector<bool>visited(N, false);
      vector<bool>inRec(N, false);
      for(int i=0;i<N;i++){
        if(!visited[i]){
          dfs(i, visited, inRec, edge);
        }
      }
      return largestSum;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends