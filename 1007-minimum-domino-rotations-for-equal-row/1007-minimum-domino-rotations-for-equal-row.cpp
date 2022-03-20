class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        vector<int> cnta(7), cntb(7), ab(7);
        int n = a.size();
        for(int i=0;i<n;i++){
            cnta[a[i]]++;
            cntb[b[i]]++;
            
            if(a[i]==b[i])
                ab[a[i]]++;
        }
        for(int i=1;i<7;i++)
            if(cnta[i] + cntb[i] - ab[i] == n)
                return (n - max(cnta[i], cntb[i]));
            
            return -1;
        
    }
};