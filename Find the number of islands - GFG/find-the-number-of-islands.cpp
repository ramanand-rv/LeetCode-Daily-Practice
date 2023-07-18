//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int N;
  int M;
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        N = grid.size();
        M = grid[0].size();
        
        vector<vector<bool>>visited(N, vector<bool>(M, false));
        int count =0;
        
        
        for(int row=0;row<N;row++){
            for(int col=0;col<M;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return count;
    }
    
    void bfs(int &row, int &col, vector<vector<bool>>& visited,  vector<vector<char>>&grid){
        visited[row][col] = true;
        queue<pair<int, int>>q;
        q.push({row, col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int drow = -1; drow<=1;drow++){
                for(int dcol = -1;dcol<=1;dcol++){
                    int nrow = row + drow;
                    int ncol = col + dcol;
                    
                    if(nrow<N && ncol < M && nrow >=0 && ncol>=0 &&
                    !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
            
            
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends