https://www.geeksforgeeks.org/problems/count-the-elements1529/1




//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    vector<int>BruteForce(vector<int> &a, vector<int> &b, int n, 
    vector<int> &query,int q)
    {
        vector<int>res;

        for(auto &qy: query){
            int num = a[qy], cnt = 0;
            for(auto &e: b){
                if(e <= num) cnt++;
            }
            res.push_back(cnt);
        }
        return res;              
                                  
    }
    
    
    vector<int>Optimized(vector<int> &a, vector<int> &b, int n, 
    vector<int> &query,int q)
    {
        int mx = -1;
        for(int i=0; i<n;i++) mx = max(mx, max(a[i], b[i]));
        // hash
        vector<int>hash(mx+1, 0);
        for(auto e:b) hash[e]++;
        
        // prefix sum
        for(int i=1;i<=mx;i++) hash[i] += hash[i-1];
        
        vector<int>res;
        for(auto qy: query) res.push_back(hash[a[qy]]);
        
        return res;
    }
    
    
    
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // return BruteForce(a, b, n, query, q);
        return Optimized(a, b, n, query, q);
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
