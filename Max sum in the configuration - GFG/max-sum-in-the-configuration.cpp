//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    int prev =0, preSum=0;
    for(int i=0;i<N;i++){
        prev += i*A[i];
        preSum += A[i];
    }
    
    int maxSum = prev;
    for(int i=1;i<N;i++){
        prev += preSum - (N* A[N-i]);
        maxSum = max(maxSum, prev);
    }
    return maxSum;
}