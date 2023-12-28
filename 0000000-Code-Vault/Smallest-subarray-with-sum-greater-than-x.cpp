//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int l=0, r=0, minSubarr = INT_MAX;
        int sum = 0, len=0;
        while(r<n){
            sum += arr[r];
            len++;

            if(sum >x){
                minSubarr = min(minSubarr, len);
                l++; r = l;
                len =0; sum =0;
            }
            else{
                r++;
            }
        }
        return (minSubarr==INT_MAX) ? 0 : minSubarr;
    }
    
            // Slidng window
/*    int smallestSubWithSum(int arr[], int n, int x)
    {
        int subarraySum = 0;
        int movingLeftIndex = 0;
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            subarraySum += arr[i];
            
            while(subarraySum > x){
                ans = min(ans, i + 1 - movingLeftIndex);
                subarraySum -= arr[movingLeftIndex];
                movingLeftIndex++;
            }
        }
        
        return (ans == INT_MAX) ? 0 : ans;
    }*/
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends
