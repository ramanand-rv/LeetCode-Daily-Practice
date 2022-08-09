class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1e9 + 7;
        
        // first of all sort the array
        sort(arr.begin(), arr.end());
        
        // declare a dp, dp[i] will store the possible binary tree till ith index
        vector<int> dp(n, 1);
        
        // declare a map, {value -> index}
        unordered_map<int, int> mp;
        // store the index to corresponding element
        
        for(int i = 0; i < n; i++)
            mp[arr[i]] = i;
        
        // fill the dp
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                // if we found one factor
                if(arr[i] % arr[j] == 0)
                {// check if other corresponding factor is present in arr or not   
                    if(mp.count(arr[i] / arr[j]))
                    {// find the index of other factor   
                        int idx = mp[arr[i] / arr[j]];
                        // update the dp[i] 
                        dp[i] = (dp[i] % mod + (dp[j] % mod * dp[idx] % mod)) % mod;
                    }
                }
            }
        }
        
        // at the end just sum up all the values of dp
        int total = 0;
        for(int i = 0; i < n; i++)
            total = (total % mod + dp[i] % mod) % mod;
        
        return total;
    }
};