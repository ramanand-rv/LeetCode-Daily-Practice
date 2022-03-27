class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i=0, n=nums.size(), count=0;
        
        while(i<n){
            
            while(i<n-1 && nums[i]==nums[i+1])i++, count++; 
             i+=2;    
        }

        if((n-count)&1)
            count++;
		
        return count;
    }
};