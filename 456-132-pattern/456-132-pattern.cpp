class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
    }
};