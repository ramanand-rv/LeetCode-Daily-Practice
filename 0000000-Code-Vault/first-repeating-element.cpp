//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        
        // TC: O(nlogn) SC: O(1) TLE
/*        for(int i=0;i<n;i++){
            if(find(arr+i+1, arr+n, arr[i]) != arr+n)
                return i+1;
        }
        return -1;*/
        
        
        // TC: (n)  SC: O(n) AC
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        for(int i=0;i<n;i++){
            if(mp[arr[i]] >1) return i+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends
