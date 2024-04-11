// https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    
    int BruteForce(int n){
         // Brute force
        
        auto d2b = [&](int n, vector<int>&bin) {
          
          while(n){
            if(n%2) bin.push_back(1);
            else bin.push_back(0);
            n /= 2;
          }
          while(bin.size() < 32) bin.push_back(0);
          reverse(bin.begin(), bin.end());
        };
        
       vector<int>bin;
        d2b(n, bin);
        
        vector<int>gc(32);
        int i=0;
        while(bin[i]==0) i++;
        
        gc[i] = bin[i];
        
        for(int j=i+1;j<32;j++)
          gc[j] = gc[j-1] ^ bin[j];
          
        int gc2dec = 0;
        for(int i=31;i>=0;i--){
          if(gc[i])
            gc2dec += pow(2, 31-i);
        }
        return gc2dec;
        
    }
    
    
    
    int BitMagic(int n){
        vector<int> grayCode(32,0);
        
        int j=0;
        while(j<=31 and (n&(1<<(31-j)))==0)
        j++;
        
        grayCode[j]=bool(n&(1<<(31-j)));
        for(int i=j+1;i<32;i++)
        {
            int bin=bool(n&(1<<(31-i)));
            int gray=grayCode[i-1];
            grayCode[i]=bin^gray;
        }
        
        int grayCodeDecimal=0;
        for(int i=31;i>=0;i--)
        {
            if(grayCode[i])
            grayCodeDecimal|=(1<<31-i);
        }
        
        return grayCodeDecimal;
    }
    
    int Optimized(int n){
        int res = 0;
        while(n>0){
            res ^= n;
            n>>=1;
        }
        return res;
    }
    
    
    int grayToBinary(int n)
    {
    //   return BruteForce(n);
    
    // return BitMagic(n);
    
    return Optimized(n);


        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends
