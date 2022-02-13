// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    int ans = 0, i=1;
    while(n>0){
        int x = n%10;
        if(x==0)
            x=5;
        
        ans += x*i;
        i *= 10;
        n /= 10;
        
    }
    
    return ans;
}