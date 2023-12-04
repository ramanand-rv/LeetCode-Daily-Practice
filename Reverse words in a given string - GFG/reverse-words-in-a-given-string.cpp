//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string tmp="", res="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                reverse(tmp.begin(), tmp.end());
                res+=tmp;
                tmp.clear();
                res+='.';
            }
            else{
                tmp+=s[i];
            }
        }
        reverse(tmp.begin(), tmp.end());
        res+=tmp;
        reverse(res.begin(), res.end());
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends