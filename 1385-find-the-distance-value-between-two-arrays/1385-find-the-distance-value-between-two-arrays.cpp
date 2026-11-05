class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        int ans = 0, j = 0;
        
        for (int x : arr1) {
            // Advance j to the first element in arr2 that is >= x - d
            while (j < arr2.size() && arr2[j] < x - d) {
                j++;
            }
            
            // If no such element exists, or it's strictly greater than x + d, x is valid
            if (j == arr2.size() || arr2[j] > x + d) {
                ans++;
            }
        }
        
        return ans;
    }
};