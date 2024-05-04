class Solution {
public:
    const int m = 1337;
    
    int binExp(int a, int b){
        int ans = 1;
        a%= m;
        while(b>0){
            if(b&1) ans = (ans *1LL* a)%m;
            a = (a*1ll*a)%m;
            b>>=1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(a==0) return 0;
        int prv = a, res = 1;
        
        for(int i=b.size()-1;i>=0;i--){
            res = (res * binExp(prv, b[i]))%m;
            prv = binExp(prv, 10);
        }
        return res;
    }
};