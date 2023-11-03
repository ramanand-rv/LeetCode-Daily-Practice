class Solution {
public:
//     Using Djikstra's Algo
//     int minimumObstacles(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         priority_queue<pair<int, pair<int, int>>, 
//         vector<pair<int, pair<int, int>>>, 
//         greater<pair<int, pair<int, int>>>>pq;
//         vector<vector<int>>result(n, vector<int>(m, INT_MAX));
//         auto isSafe = [&] (int r, int c){
//             return r>=0 && c>=0 && r<n && c<m;
//         };
//         vector<vector<int>>directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        
//         result[0][0] = 0;
//         pq.push({0, {0, 0}});
        
//         while(!pq.empty()){
//             int blocks = pq.top().first;
//             auto coord = pq.top().second;
//             int row = coord.first;
//             int col = coord.second;
//             pq.pop();
            
//             for(auto &dir: directions){
//                 int nr = row + dir[0];
//                 int nc = col + dir[1];
                
//                 if(isSafe(nr, nc)){
//                     if(blocks + grid[nr][nc] < result[nr][nc]){
//                         result[nr][nc] = blocks + grid[nr][nc];
//                         pq.push({blocks + grid[nr][nc], {nr, nc}});
//                     }
//                 }
//             }
//         }
//         return result[n-1][m-1];
//     }

// Using BFS (Deque)
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        auto isSafe = [&] (int r, int c){
            return r>=0 && c>=0 && r<n && c<m && !visited[r][c];
        };
        vector<vector<int>>directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        deque<pair<int, int>>q;
        q.push_front({0, 0});
        dp[0][0] = grid[0][0];
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            
            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                
                if(isSafe(x_, y_)){
                    dp[x_][y_] = dp[x][y] + (grid[x_][y_] == 1);
                    if(grid[x_][y_] == 1)
                        q.push_back({x_, y_});
                    else
                        q.push_front({x_, y_});
                    visited[x_][y_] = true;
                }
            }
        }
        return dp[n-1][m-1];
    }

};