class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int N = pref.size();
        vector<int>op(N);
        op[0] = pref[0];
        for(int i=1;i<N;i++)
            op[i] = (pref[i]^pref[i-1]);
        return op;
    }
};