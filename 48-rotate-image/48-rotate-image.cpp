class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        int a = 0, b = n-1;
        
        while(a<b){
            for(int i=0; i<(b-a); i++){
                swap(m[a][a+i], m[a+i][b]);
                swap(m[a][a+i], m[b][b-i]);
                swap(m[a][a+i], m[b-i][a]);
            }
            a++;
            b--;   
        } 
    }
};