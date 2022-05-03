class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        int n = v.size();
        for(int i=0, j=0; j<n;j++){
            if(v[j]%2 ==0)
                swap(v[i++], v[j]);
        }
        
        return v;
    }
};