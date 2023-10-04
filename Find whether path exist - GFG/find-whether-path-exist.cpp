//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int N;
    int target_x, target_y;
    vector<vector<bool>>visited;
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        N = grid.size();
        visited.resize(N, vector<bool>(N, false));
        int xsrc, ysrc;
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                if(grid[row][col]==1){
                    if(dfs(row, col, grid))    return true;
                }
            }
        }
        return false;
    }
    
    
    bool dfs(int row, int col, vector<vector<int>>& grid){
        if(grid[row][col]==2)  return true;
        grid[row][col] = -1;
                
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0}; 
        
        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            if( nr>=0 && nc>=0 && nr<N && nc<N && grid[nr][nc] >= 2 ){
                if( dfs(nr, nc, grid) ) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends