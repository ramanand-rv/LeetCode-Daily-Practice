class Solution {
public:
    bool isPrime[1000];
    
    void sieve(){
        fill(isPrime, isPrime+1000, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i<1000;i++){
            if(isPrime[i]){
                for(int k=i*i; k< 1000; k+=i)
                    isPrime[k] = false;
            }
        }
    }
    
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        for(int i=nums.size()-2;i>=0;--i){
            if(nums[i] >= nums[i+1]){
                for(int p=2;p<nums[i];p++){
                    if(isPrime[p] && (nums[i] - p < nums[i+1])){
                        nums[i] -= p;
                        break;
                    }
                }
                if(nums[i] >= nums[i+1])
                    return false;
            }
        }
        return true;
    }
};