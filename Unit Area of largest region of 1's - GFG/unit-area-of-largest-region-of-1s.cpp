//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int N, M;
    int result=0;
    int count=0;
    
    
    void dfs(int row, int col, vector<vector<int>>& grid){
        if (row < 0 || row >= N || col < 0 || col >= M || grid[row][col] == 0) return;
        grid[row][col] = 2;
        count++;
        
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0 };
        int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1 };
        for(int i=0;i<8;i++){
            int nr = row + delRow[i];
            int nc = col + delCol[i];

            if(nr>=0 && nr<N && nc>=0 && nc<M && grid[nr][nc]==1){
                dfs(nr, nc, grid);
            }
        }
    }
    

    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        vector<vector<bool>>visited(N, vector<bool>(N, false));
        for(int row=0;row<N;row++){
            for(int col=0;col<M;col++){
                if(grid[row][col]==1){
                    dfs(row, col, grid);
                    result = max(result, count);
                    count=0;
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends