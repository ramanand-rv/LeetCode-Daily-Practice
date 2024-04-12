class Solution {
public:
    int trap(vector<int>& arr) {
         int res = 0; int n = arr.size(); 
  
        for (int i = 1; i < n - 1; i++) { 

            int left = arr[i]; 
            for (int j = 0; j < i; j++) 
                left = max(left, arr[j]); 

            int right = arr[i]; 
            for (int j = i + 1; j < n; j++) 
                right = max(right, arr[j]); 

            res = res + (min(left, right) - arr[i]); 
        } 

        return res; 
    }
};