class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0=0, cnt1=0, cnt2=0;
        for (int x : stones) {
            if (x % 3 == 0) cnt0++;
            else if (x % 3 == 1) cnt1++;
            else cnt2++;
        }
        if (cnt0 % 2 == 0)
            return cnt1 > 0 && cnt2 > 0;
        return abs(cnt1 - cnt2) > 2;
    }
};