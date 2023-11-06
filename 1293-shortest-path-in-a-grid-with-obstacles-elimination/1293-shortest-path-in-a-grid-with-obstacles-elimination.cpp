class Solution {
public:
    
//    Clears 50% TCs (using BFS) 
  int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 && n ==1) return 0;
        int steps = 0;
        bool visited[41][41][1681];
        memset(visited, false, sizeof(visited));
        vector<vector<int>>directions = {{1, 0}, {0, 1}, 
                                         {0, -1}, {-1, 0}};
        queue<vector<int>>q;
        auto isSafe = [&] (int r, int c){
            return r>=0 && c>=0 && r<m && c<n;
        };

        q.push({0, 0, k});
        visited[0][0][k] = true;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                q.pop();
                
                if(cur[0]==m-1 && cur[1]==n-1) return steps;
                
                for(auto &dir: directions){
                    int x_ = cur[0] + dir[0];
                    int y_ = cur[1] + dir[1];
                    int obs = cur[2];

                    if(isSafe(x_, y_)){
                        if(grid[x_][y_]==0 && !visited[x_][y_][obs]){
                            q.push({x_, y_, obs});
                            visited[x_][y_][obs] = true;
                        }
                        else if(grid[x_][y_]==1 && obs>0 && !visited[x_][y_][obs-1]){
                            q.push({x_, y_, obs-1});
                            visited[x_][y_][obs-1] = true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;;
    }

    
    
    
    
    
    
    
    
    
//     Passes 95% test cases:
//     1. Find the number of steps in shortest path using BFS
//     2. Count the number of walls encountered int the shortest path
//     3. if number of walls is <= K return the number of steps
//     4. Else return -1
    
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int steps = 0;
        
//         if(m==1 && n ==1) return 0;
        
//         vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
//         vector<vector<bool>>visited(m, vector<bool>(n, false));
//         vector<vector<int>>directions = {{1, 0}, {0, 1}, 
//                                          {0, -1}, {-1, 0}};
//         queue<pair<int, pair<int, int>>>q;
//         auto isSafe = [&] (int r, int c){
//             return r>=0 && c>=0 && r<m && c<n && !visited[r][c];
//         };
        
//         q.push({grid[0][0], {0, 0}});
                
//         while(!q.empty()){
//             int qSize = q.size();
//             steps++;
//             while(qSize--){
//                 int w = q.front().first;
//                 auto coord = q.front().second;
//                 int x = coord.first;
//                 int y = coord.second;
//                 q.pop();
//                 for(auto &dir: directions){
//                     int x_ = x + dir[0];
//                     int y_ = y + dir[1];
                    
//                     if(isSafe(x_, y_)){
//                         if(dp[x_][y_] > w + grid[x_][y_]){
//                             dp[x_][y_] = w + grid[x_][y_];
//                             q.push({w+grid[x_][y_], {x_, y_}});
//                             visited[x_][y_] = true;
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[m-1][n-1] <= k ? steps-1 : -1;
//     }
};