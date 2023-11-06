class Solution {
public:
    
//    Passes 100% TCs (using BFS) 
//     1. In Queue and Visited store {m, n, k}
//     2. Start BFS Traversal, count number of steps;
//          if x==m-1 && y==n-1 return steps
    
//     3. If grid[m][n]==0 (no wall) && [m, n, k] is not visited:
//          push {m, n, k} in q;
//          and mark [m, n, k] as visited 
    
//     4. If grid[m][n]==1 (wall) && [m, n, k-1] is not visited:
//          push {m, n, k-1} in q;
//          and mark [m, n, k-1] as visited
    
//     5. Return -1 on finishing the traversal
    
    
//   int shortestPath(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         if(m==1 && n ==1) return 0;
//         int steps = 0;
//         bool visited[41][41][1681];
//         memset(visited, false, sizeof(visited));
//         vector<vector<int>>directions = {{1, 0}, {0, 1}, 
//                                          {0, -1}, {-1, 0}};
//         queue<vector<int>>q;
//         auto isSafe = [&] (int r, int c){
//             return r>=0 && c>=0 && r<m && c<n;
//         };

//         q.push({0, 0, k});
//         visited[0][0][k] = true;

//         while(!q.empty()){
//             int sz = q.size();
//             while(sz--){
//                 auto cur = q.front();
//                 q.pop();
                
//                 if(cur[0]==m-1 && cur[1]==n-1) return steps;
                
//                 for(auto &dir: directions){
//                     int x_ = cur[0] + dir[0];
//                     int y_ = cur[1] + dir[1];
//                     int obs = cur[2];

//                     if(isSafe(x_, y_)){
//                         if(grid[x_][y_]==0 && !visited[x_][y_][obs]){
//                             q.push({x_, y_, obs});
//                             visited[x_][y_][obs] = true;
//                         }
//                         else if(grid[x_][y_]==1 && obs>0 && !visited[x_][y_][obs-1]){
//                             q.push({x_, y_, obs-1});
//                             visited[x_][y_][obs-1] = true;
//                         }
//                     }
//                 }
//             }
//             steps++;
//         }
//         return -1;;
//     }

    
    
    
    
    
    
    
    
    
//     Using Djikstra's Algo
//     1. Use a vector {steps, k, x, y} within priority queue
//     2. Start BFS Traversal
//     3. if x==m-1 && y==n-1 return steps
//     4. go to new valid cell x_, y_
//     5. calc rem->remaining walls that can be broken from current cell:
//          rem =  k - 
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int steps = 0;
        
        if(m==1 && n ==1) return 0;
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        bool visited[41][41][1681];
        memset(visited, false, sizeof(visited));
        vector<vector<int>>directions = {{1, 0}, {0, 1}, 
                                         {0, -1}, {-1, 0}};
        priority_queue<vector<int>, 
            vector<vector<int>>, 
            greater<vector<int>> >q;
        auto isSafe = [&] (int r, int c){
            return r>=0 && c>=0 && r<m && c<n;
        };
//         {steps, k, x, y}
        q.push({0, k, 0, 0});
        while(!q.empty()){
            int steps = q.top()[0];
            int canBreak = q.top()[1];
            int x = q.top()[2];
            int y = q.top()[3];
            q.pop();
            if(x==m-1 && y==n-1) return steps;
            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_)){
                    int rem = canBreak - (grid[x_][y_]);
                    if(rem >=0 && rem > dp[x_][y_] ){
                        q.push({steps+1, rem, x_, y_});
                        dp[x_][y_] = rem;
                    }
                    }
                }
            }
        return -1;
        }
};