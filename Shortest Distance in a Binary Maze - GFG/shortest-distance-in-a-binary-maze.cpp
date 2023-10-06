//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         if(source.first == destination.first && 
                         source.second == destination.second)   return 0;
                         if(grid[source.first][source.second] == 0 && 
                         grid[destination.first][destination.second]==0)    return -1;
                         int N = grid.size();
                         int M = grid[0].size();
                         vector<vector<int>>res(N, vector<int>(M, INT_MAX));
                         queue<pair<int, int>>q;
                         q.push({source.first, source.second});
                         res[source.first][source.second] = 0;
                         
                         while(!q.empty()){
                             int r = q.front().first;
                             int c = q.front().second;
                             q.pop();
                             
                             int dx[] = {1, 0, -1, 0};
                             int dy[] = {0, 1, 0, -1};
                             for(int i=0;i<4;i++){
                                 int nr = r + dx[i];
                                 int nc = c + dy[i];
                                 
                                 if(nr>=0 && nc>=0 && nr<N && nc<M && grid[nr][nc]==1){
                                     if(res[nr][nc] > res[r][c]+1){
                                         res[nr][nc] = res[r][c]+1;
                                         q.push({nr, nc});
                                     }
                                 }
                             }
                             
                         }
                         if(res[destination.first][destination.second] != INT_MAX)
                            return res[destination.first][destination.second];
                        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends