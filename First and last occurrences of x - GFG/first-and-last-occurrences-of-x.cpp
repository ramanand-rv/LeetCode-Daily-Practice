//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int binarySearch(int arr[], int n, int target, bool isFirstIdx){
        int start = 0, end = n-1, ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target < arr[mid])
                end = mid -1;
            else if(target > arr[mid])
                start = mid +1;
            else{
                ans = mid;
                if(isFirstIdx)
                    end = mid -1;
                else
                    start = mid +1;
            }
        }
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>res(2, -1);
        res[0] = binarySearch(arr, n, x, true);
        res[1] = binarySearch(arr, n, x, false);
            
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends