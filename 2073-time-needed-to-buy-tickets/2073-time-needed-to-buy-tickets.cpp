class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int value = tickets[k];
        int time = 0;
        
        for(int i=0;i<tickets.size();i++){
            int maxBuy = (i<=k) ? value : value - 1;
            time += (tickets[i] > maxBuy) ? maxBuy : tickets[i];
        }
        return time;
    }
};