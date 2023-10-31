class Solution {
public:
    int mod = 1e9 + 7;
    int N, M;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        N=grid.size(); M=grid[0].size();
        vector<vector<vector<int>>>dp(N, vector<vector<int>>(
                                      M, vector<int>(51, -1)));
        return solve(grid, k, 0, 0, 0, dp);
    }
    
    int solve(vector<vector<int>>& grid, int k, int i, int j, int sum, 
              vector<vector<vector<int>>>&dp){
        if(i<0||j<0||i>=N||j>=M)
            return 0;
        if( i == N-1 && j == M-1 ){
            sum += grid[i][j];
            return sum%k==0?1:0;
        }
        if(dp[i][j][sum%k] != -1) return dp[i][j][sum%k];

        //  Move Right
        long long int rightSum = solve(grid, k, i, j+1, sum+grid[i][j], dp);

        //  Move Down
        long long int downSum = solve(grid, k, i+1, j, sum+grid[i][j], dp);

        return dp[i][j][sum%k] = ((rightSum % mod) + (downSum % mod)) % mod;
    }
};

