//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    if(n==0) return {0, 0};
	    int l=0, r=0;
	    
	    int mn = arr[0];
	    for(int i=0;i<n;i++){
	        if(arr[i] < mn) r = i;
            mn = max(mn, arr[i]);
	    }
	    
	    int mx = arr[n-1];
	    for(int i=n-1;i>=0;i--){
	        if(arr[i] > mx) l = i;
	        mx = min(mx, arr[i]);
	    }
	    return {l, r};
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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends