#include<bits/stdc++.h>
using namespace std;

void solve(){
int n, k;
cin>>n>>k;
vector<int>v(n);
for(int i=0; i<n;i++){
    cin>>v[i];
}
// sort(v.begin(), v.end());
rotate(v.begin(), v.begin() + k, v.end());

for(auto val:v)
    cout<<val<<" ";
    
cout<<endl;
}


int main()
 {
	int TC;
    cin>>TC;
    while(TC--){
    solve();
    }
    
    
	return 0;
}