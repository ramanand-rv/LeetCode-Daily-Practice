
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {

        vector<int>res;
        for(int i=0;i<n;i++) arr[ arr[i] % n ] += n;
        for(int i=0;i<n;i++){
            if(arr[i] / n > 1) res.push_back(i);
        }
        
        if(res.size() == 0) return {-1};
        return res;
    }
};













//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        vector<int>res;
        
/*        map<int, int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        for(auto e: mp) if(e.second>=2) res.push_back(e.first);
    
        if(res.size() == 0) return {-1};
        return res;*/
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
