class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        int l=0, r = m*n-1;
        
        while(l != r){
            int mid = (l + r - 1)>>1;
            if(v[mid/m][mid%m] < t)
                l = mid + 1;
            else
                r = mid;
            
        }
        
        return v[r/m][r%m] == t;
    }
};