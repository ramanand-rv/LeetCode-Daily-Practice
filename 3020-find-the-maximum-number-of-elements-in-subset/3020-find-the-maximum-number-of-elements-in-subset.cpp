class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, long long> freq;
        long long ans = 0;

        for (auto& n : nums)
            freq[n]++;

        for (auto& x : freq) {
            long long curNum = x.first;

            // special case
            if (curNum == 1) {
                ans = max(ans, (freq[1] % 2 == 0 ? freq[1] - 1 : freq[1]));
                continue;
            }

            long long curLength = 0;

            while (freq.count(curNum) && freq[curNum] >= 2) {
                curLength += 2;
                curNum *= curNum;
            }

            if (freq.count(curNum) && freq[curNum] == 1)
                curLength++;
            else
                curLength--;

            ans = max(ans, curLength);
        }

        return ans;
    }
};