class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n = pushed.size();
        int i=0;
        for(int c: pushed){
            st.push(c);
        while(st.size() && st.top()== popped[i]){
            st.pop();
            i++;
        }
        
    }
        
        return st.size()==0;
    }
};