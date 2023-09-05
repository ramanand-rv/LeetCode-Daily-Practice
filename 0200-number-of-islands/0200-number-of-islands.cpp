class Solution {
public:
    int N, M;
    vector<vector<bool>>visited;
    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        visited.resize(N, vector<bool>(M, false));
        int islands = 0;
        
        for(int row=0;row<N;row++){
            for(int col=0;col<M;col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    dfs(row, col, grid);
                    islands++;
                }
            }
        }
        return islands;   
    }
    
    void dfs(int row, int col, vector<vector<char>>& grid){
        visited[row][col] = true;
        
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};        
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow<N && nrow>=0 && ncol<M && ncol>=0 
               && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid);    
            }
        }
    }
};