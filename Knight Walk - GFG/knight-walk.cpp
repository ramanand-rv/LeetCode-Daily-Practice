//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int x = KnightPos[0]-1;
	    int y = KnightPos[1]-1;
	    
	    int tx = TargetPos[0]-1;
	    int ty = TargetPos[1]-1;
	    if(x==tx && y==ty)  return 0;
	    queue<pair<int, int>>q;
	    vector<vector<bool>>visited(N, vector<bool>(N, false));
	    q.push({x, y});
	    visited[x][y] = true;
	    int ans = 0;
	    
	    while(!q.empty()){
	        ans++;
	        int size = q.size();
	        while(size--){
	            int curx = q.front().first;
	            int cury = q.front().second;
	            q.pop();
	            
	            int dx[] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int dy[] = {2, -2, 2, -2, 1, 1, -1, -1};
	            for(int i=0;i<8;i++){
	                int nx = curx + dx[i];
	                int ny = cury + dy[i];
	                
	                if(isTarget(nx, ny, TargetPos)) return ans;
	                
	                if(isValid(nx, ny, N, visited)){
	                    visited[nx][ny] = true;
	                    q.push({nx, ny});
	                }
	            }
	        }
	    }
	    return -1;
	}
	
// 	bool dfs(int row, int col, vector<int>&TargetPos, int N, int& res,  vector<vector<bool>>& visited){
// 	    visited[row][col] = true;
//         if(isTarget(row, col, TargetPos)) return true;
// 	    res++;
	    
// 	    int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
// 	    int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	    
// 	    for(int i=0;i<8;i++){
//             int newRow = row + dr[i];
//             int newCol = col + dc[i];
            
//             if(isValid(newRow, newCol, N, visited)){
//                 dfs(newRow, newCol, TargetPos, N, res, visited);
//             }
//         }
// 	}
	bool isValid(int nr, int nc, int N, vector<vector<bool>>& visited){
	    if(nr>=0 && nr<N && nc>=0 && nc<N && !visited[nr][nc])
	        return true;
        return false;
	}
	bool isTarget(int r, int c, vector<int>& target){
	    if(r == target[0] -1 && c == target[1] -1)
	        return true;
        return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends