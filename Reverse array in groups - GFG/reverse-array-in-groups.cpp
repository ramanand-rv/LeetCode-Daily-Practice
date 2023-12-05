//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // Methid 1
/*        for(int i=0;i<n;i+=k){
            int l=i, r=min(i+k-1, n-1);
            while(l<r){
                swap(arr[l], arr[r]);l++;r--;
            }
        }*/
        
        // method 2
        long long l=0, r=k;
        while(r<n){
            reverse(arr.begin() +l, arr.begin() +r);
            l+=k;
            r+=k;
        }
        reverse(arr.begin()+l, arr.begin()+n);
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends