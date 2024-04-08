class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int>cnt(2);
        
        for(auto s: students)
            ++cnt[s];
        
        for(int i=0;i<sandwiches.size();++i){
            if(cnt[sandwiches[i]] == 0)
                return sandwiches.size() -i;
            
            --cnt[sandwiches[i]];
        }
        return 0;
    }
};