class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        int pt = n-1;

        while(k>0){
            res[pt--] += min(k, 25);
            k -= min(k, 25);
        }
        
        return res;
    }
};