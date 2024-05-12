class Solution {
public:
    int N, M;
    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};  
    vector<vector<bool>>visited;
    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        visited.resize(N, vector<bool>(M, false));
        int islands = 0;
        
        for(int row=0;row<N;row++){
            for(int col=0;col<M;col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    // dfs(row, col, grid);
                    // bfs(row, col, grid);
                    dfs2(row, col, grid);
                    islands++;
                }
            }
        }
        return islands;   
    }
    
//     Using DFS
    void dfs(int row, int col, vector<vector<char>>& grid){
        visited[row][col] = true;
              
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow<N && nrow>=0 && ncol<M && ncol>=0 
               && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid);    
            }
        }
    }
    
    
//     Using BFS
    void bfs(int row, int col, vector<vector<char>>& grid){
        queue<pair<int, int>>q;
        q.push({row, col});
        visited[row][col] = true;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0; i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                
                if(nr<N && nc<M && nr>=0 && nc>=0 && !visited[nr][nc] && grid[nr][nc]=='1'){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
    
    void dfs2(int row, int col, vector<vector<char>>& grid){
        if(row<0 || row >=N || col<0 || col>=M || grid[row][col]=='0' || grid[row][col]=='x')
            return;
        // visited[row][col] = true;
        grid[row][col] = 'x';
        dfs2(row+1, col, grid);
        dfs2(row-1, col, grid);
        dfs2(row, col+1, grid);
        dfs2(row, col-1, grid);
        
    }
};