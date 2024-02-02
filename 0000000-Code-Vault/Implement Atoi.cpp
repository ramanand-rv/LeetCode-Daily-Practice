https://www.geeksforgeeks.org/problems/implement-atoi/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        long long res = 0;

        bool neg = false;
            
        for(int i=0;i<s.size(); ++i){
            if(i==0 && (int)s[0] == (int)'-'){
                neg = true;
                continue;
            }
            else if((int)s[i] >= (int)'0' && (int)s[i] <= (int)'9'){
                res+=s[i]-'0';
                res*=10;
            }
            else return -1;
                
        }
        return neg ? (res/10 * -1) : res/10;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
