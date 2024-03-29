//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!='?' && s[n-1-i]=='?')
                s[n-1-i] = s[i];
            
            if(s[i]=='?' && s[n-1-i]!='?')
                s[i] = s[n-1-i];
            
            if(s[i]!=s[n-1-i] && s[i]!='?' && s[n-1-i]!='?')
                return -1;
        }
        
        int res=0;
        char prevChar = '.';
        for(int i=0;i<n/2;i++){
            if(s[i]!='?'){
                if(prevChar=='.')
                    prevChar = s[i];
                else if(prevChar != s[i])https://www.geeksforgeeks.org/jobs?tab=studentjobfair
                    res += abs(s[i] - prevChar);
                prevChar = s[i]; 
            }
        }
        
        return res*2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends