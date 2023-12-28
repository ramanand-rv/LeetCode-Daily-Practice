//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        int l=0, r=arr.size()-1, minDiff = INT_MAX;
        vector<int>res;
        while(l<r){
            int sum = arr[l]+arr[r];
            int diff = abs(x - sum);
            res.clear();
            
            if(diff < minDiff){
                minDiff = diff;
                res.push_back({arr[l]});
                res.push_back({arr[r]});
            }
            
            if(sum < x) l++;
            else r--;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends