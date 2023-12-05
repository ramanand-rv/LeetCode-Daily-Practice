//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
/*        sort(arr, arr+n, greater<int>());
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(arr[i]);
        }
        return res;*/
        
        priority_queue<int>q;
        vector<int>res;
        for(int i=0;i<n;i++) q.push(arr[i]);
        while(res.size()<k){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends