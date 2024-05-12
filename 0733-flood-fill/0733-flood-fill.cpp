class Solution {
public:
    int n, m;
    void dfs(int r, int c, vector<vector<int>>& image, int ogclr, int nclr){
        if(r <0 || c <0) return;
        if(r>=n || c>=m) return;
        if(image[r][c] != ogclr) return;
        
        image[r][c] = nclr;
        
        
        dfs(r+1, c, image, ogclr, nclr);
        dfs(r-1, c, image, ogclr, nclr);
        dfs(r, c+1, image, ogclr, nclr);
        dfs(r, c-1, image, ogclr, nclr);
        
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