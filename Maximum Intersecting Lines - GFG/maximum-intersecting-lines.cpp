//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        //   list<int> li;
        //   int res=0;
    int maxIntersections(vector<vector<int>>& lines, int N) {
        // Code here
        map<int, int> mp;
        for(auto it:lines){
            int s = it[0];
            int e = it[1];
            mp[s]++;
            mp[e+1]--;
        }
        int res=1;
        int presum=0;
        for(auto it:mp){
            presum += it.second;
            res = max(res, presum);
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends