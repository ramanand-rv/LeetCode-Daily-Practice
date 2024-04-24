class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        
        int res = 0, x=0, y=1, z=1;
        
        for(int i=0;i<n-2;i++){
            res = x+y+z;
            x=y;
            y=z;
            z=res;
        }
        return z;
    }
};