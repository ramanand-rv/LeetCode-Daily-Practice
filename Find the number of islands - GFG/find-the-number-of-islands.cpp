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
        int count=0;
        vector<vector<bool>>visited(N, vector<bool>(M, false));
        for(int row=0;row<N;row++){
            for(int col=0;col<M;col++){
                if(!visited[row][col] && grid[row][col] == '1' ){
                  count++;
                //   dfs(row, col, grid, visited);
                  bfs(row, col, grid, visited);
                }
            }
        }
        return count;
    }
    
    // void dfs(int row, int col, vector<vector<char>>&grid, vector<vector<bool>>&visited){
    //     visited[row][col] = true;
        
    //     for(int dr = -1; dr<=1; dr++){
    //         for(int dc = -1; dc<=1; dc++){
    //             int nrow = row + dr;
    //             int ncol = col + dc;
                
    //             if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
    //                 dfs(nrow, ncol, grid, visited);
    //             }
    //         }
    //     }
    // }
    
    void bfs(int &row, int &col, vector<vector<char>>&grid, vector<vector<bool>>&visited){
        queue<pair<int, int>>q;
        visited[row][col] = true;
        q.push({row, col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int dr=-1;dr<=1;dr++){
                for(int dc= -1;dc<=1;dc++){
                    int nrow = row + dr;
                    int ncol = col + dc;
                    
                    if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = true;
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