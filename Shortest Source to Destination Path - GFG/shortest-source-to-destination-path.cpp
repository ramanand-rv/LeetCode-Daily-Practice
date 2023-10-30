//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> arr, int x, int y) {
        if(arr[x][y]==0 || arr[0][0]==0)    return -1;
        if(x==0 && y==0) return 0;
        vector<vector<int>>res(N, vector<int>(M, INT_MAX));
        
        queue<pair<int, int>>q;
        q.push({0, 0});
        res[0][0] = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            arr[r][c] = -1;

            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                
                if(nr>=0 && nc>=0 && nr<N && nc<M && arr[nr][nc]==1){
                                    
                  if(res[nr][nc] > res[r][c]){
                      res[nr][nc] = res[r][c] + 1;
                      q.push({nr, nc});
                      arr[nr][nc] = -1;
                    }
                }
            }
        }
        if(res[x][y] != INT_MAX)    return res[x][y];
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends