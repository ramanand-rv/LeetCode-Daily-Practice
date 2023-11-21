//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
   
    void swap(vector<int>&arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

//---------------------------------------------------------------------------
// TLE, O(N^2), 10/50
/*    int indexOf(vector<int>& arr, int element){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==element)
                return i;
        }
        return -1;
    }
    
	int minSwaps(vector<int>&nums)
	{
	    vector<int>tmp(nums.begin(), nums.end());
	    sort(tmp.begin(), tmp.end());
	    int ans = 0;
	    
	    for(int i=0;i<nums.size();i++){
	        if(nums[i] != tmp[i]){
	            ans++;
	            swap(nums, i, indexOf(nums, tmp[i]) );
	        }
	    }
	    return ans;
	}*/
	
// 	-------------------------------------------------------------------------
	int minSwaps(vector<int>&nums){
	    vector<int>tmp(nums.begin(), nums.end());
	    sort(tmp.begin(), tmp.end());
	    int ans = 0;
	    
	    unordered_map<int, int>mp;
	    for(int i=0;i<nums.size();i++){
	        mp[nums[i]] = i;
	    }
	    
	    for(int i=0;i<nums.size();i++){
	        if(nums[i] != tmp[i]){
	                ans++;
	                int cur = nums[i];
	                
	                swap(nums, i, mp[tmp[i]]);
	                
	                mp[cur] = mp[tmp[i]];
	                tmp[i] = nums[i];
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends