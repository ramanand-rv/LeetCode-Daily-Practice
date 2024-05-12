class Solution {
public:
    int n, m;
    vector<int>dirx={1, 0, -1, 0};
    vector<int>diry={0, 1, 0, -1};
//     void dfs(int r, int c, vector<vector<int>>& image, int ogclr, int nclr){
//         if(r <0 || c <0) return;
//         if(r>=n || c>=m) return;
//         if(image[r][c] != ogclr) return;
        
//         image[r][c] = nclr;
        
//         dfs(r+1, c, image, ogclr, nclr);
//         dfs(r-1, c, image, ogclr, nclr);
//         dfs(r, c+1, image, ogclr, nclr);
//         dfs(r, c-1, image, ogclr, nclr);
//     }
    
    void dfs(int r, int c, vector<vector<int>>& image, int ogclr, int nclr){
            image[r][c] = nclr;
            
            int x, y;
            for(int i=0;i<4;i++){
                x = r + dirx[i];
                y = c + diry[i];
                
                if(x < n && x>=0 && y<m && y>=0 && image[x][y]==ogclr){
                    dfs(x, y, image, ogclr, nclr);
                }
            }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogc = image[sr][sc];
        n = image.size();
        m = image[0].size();
        if(image[sr][sc] != color)
            dfs(sr, sc, image, ogc, color);
        return image;
    }
};