class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> map(10001);
        for (int num : nums) {
            map[num] += num;
        }
        int prev = 0;
        int curr = 0;
        int temp;
        for (int value : map) {
            temp = curr;
            curr = max(curr, prev + value);
            prev = temp;
        }
        return curr;
    }
};