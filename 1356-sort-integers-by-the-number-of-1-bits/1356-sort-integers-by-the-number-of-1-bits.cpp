class Solution {
public:
    int countOnes(int n){
        int count=0;
        while(n){
            count += (n & 1);
            n>>=1;
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&] (int &a, int &b){
        int count_a = countOnes(a);
        int count_b = countOnes(b);
        if( count_a == count_b)
            return a<b;
        return count_a < count_b;
        };
        
        auto lambda2 = [] (int &a, int &b) {
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);
            if(count_a == count_b) return a<b;
            return count_a < count_b;
        };
        
        // sort(begin(arr), end(arr), lambda);
        sort(begin(arr), end(arr), lambda2);    
        return arr;
    }
    

};