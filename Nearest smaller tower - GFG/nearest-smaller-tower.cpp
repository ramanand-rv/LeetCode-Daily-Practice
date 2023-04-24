//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
vector<int>res;
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        stack<int> st;
        vector<int>start, end;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(st.empty()){
                start.push_back(-1);
                st.push(i);
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                
                if(st.empty()){
                    start.push_back(-1);
                    st.push(i);
                }
                else{
                    start.push_back(st.top());
                    st.push(i);
                }
            }
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=n-1; i>=0;i--){
            if(st.empty()){
                end.push_back(-1);
                st.push(i);
            }
            else{
                while(!st.empty() &&arr[st.top()] >= arr[i])
                    st.pop();
                    
                if(st.empty()){
                    end.push_back(-1);
                    st.push(i);
                }
                else{
                    end.push_back(st.top());
                    st.push(i);
                }
            }
        }
        
        vector<int>ans;
        reverse(end.begin(), end.end());
        
        for(int i=0; i<n; i++){
            if(end[i]==-1 && start[i]==-1){
                ans.push_back(-1);
                continue;
            }
            if(end[i]==-1 && start[i] != -1){
                ans.push_back(start[i]);
                continue;
            }
            if(end[i] != -1 && start[i]==-1){
                ans.push_back(end[i]);
                continue;
            }
            if(abs(i - end[i]) > abs(i - start[i])){
                ans.push_back(start[i]);
                continue;
            }
            else if(abs(i - end[i]) < abs(i - start[i])){
                ans.push_back(end[i]);
            }
            else{
                if(arr[end[i]] < arr[start[i]]){
                    ans.push_back(end[i]);
                }
                else{
                    ans.push_back(start[i]);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends