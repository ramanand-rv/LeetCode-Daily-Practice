class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        unordered_map<int,int> ump;

        for(int &num: nums){
            ump[num]++;
        }

        int n = nums.size()/2;
        for(auto e: ump){
            if(e.second > n){
                return e.first;
            }
        }
        return 0;
        */
        int count=0, candidate=0;
        for(int num: nums){
            if( count == 0){
                candidate = num;
            }
            if(num == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};