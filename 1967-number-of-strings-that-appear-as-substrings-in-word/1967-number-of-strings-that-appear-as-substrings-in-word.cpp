class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int subs = 0;
        for(string &s: patterns){
            if(word.find(s) != string::npos)
                subs++;
        }
        return subs;
    }
};