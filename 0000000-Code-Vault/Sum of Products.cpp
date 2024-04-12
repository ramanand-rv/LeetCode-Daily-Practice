https://www.geeksforgeeks.org/problems/sum-of-products5049/1




//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long BruteForce(int n, long long arr[]){
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j) continue;
                res += (arr[i] & arr[j]);
            }
        }
        return res;
    }
    
    
    long long Optimized(int n, long long arr[]){
        long long res = 0;
        
        for(int i=0;i<32;i++){
            long long count = 0;
            for(int j=0;j<n;j++){
                if(arr[j] & (1<<i))
                    count++;
            }
            res += (count * (count -1)/2 * (1LL << i));
        }
        return res;
    }
    
    
    long long pairAndSum(int n, long long arr[]) {
        // return BruteForce(n, arr);
        return Optimized(n, arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
