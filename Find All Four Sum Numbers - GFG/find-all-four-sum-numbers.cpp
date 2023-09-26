//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int t) {
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
    
        for(int i=0;i<n;i++){
            if(i >0 && arr[i] == arr[i-1])  continue;
            for(int j=i+1;j<n;j++){
                if(j != (i+1) && arr[j]==arr[j-1])  continue;
                int rem = t - (arr[i] + arr[j]);
            
                int l = j+1;
                int r = n-1;
                
                while(l<r){
                    if(arr[l] + arr[r] == rem){
                        vector<int>tmp = {arr[i], arr[j], arr[l], arr[r]};
                        ans.push_back(tmp);
                        l++; r--;
                        while(l < r && arr[l] == arr[l-1]) l++;
                        while(l < r && arr[r] == arr[r+1]) r--;
                    }
                    else if( arr[l] + arr[r] > rem) r--;
                    else l++;
                }
            }
        }
        return ans;
        
        
        
    // Using Hash Table (only finds 1 quadruple)
    
// 	unordered_map<int, pair<int, int> > mp;
// 	for (int i = 0; i < n - 1; i++)
// 		for (int j = i + 1; j < n; j++)
// 			mp[arr[i] + arr[j]] = { i, j };

// 	for (int i = 0; i < n - 1; i++) {
// 		for (int j = i + 1; j < n; j++) {
// 			int sum = arr[i] + arr[j];
// 			if (mp.find(X - sum) != mp.end()) {

// 				pair<int, int> p = mp[X - sum];
// 				if (p.first != i && p.first != j
// 					&& p.second != i && p.second != j) {
// 					cout << arr[i] << ", " << arr[j] << ", "
// 						<< arr[p.first] << ", "
// 						<< arr[p.second];
// 					return;
// 				}
// 			}
// 		}
// 	}
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends