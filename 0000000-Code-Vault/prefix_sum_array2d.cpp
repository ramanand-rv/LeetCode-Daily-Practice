#include <iostream>
using namespace std;
const int N = 1e4+10;
int a[N][N];
int pf[N][N];

int main() 
{
  int n; cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
      pf[i][j] = a[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1]; 
    }
  }  
  int t=1;
  while(t--){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<< pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1]<<endl;
  }

}



