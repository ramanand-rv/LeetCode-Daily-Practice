class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>res(n);
        deque<int>q(n);
        sort(deck.begin(), deck.end());
        
        iota(q.begin(), q.end(), 0);
        
        for(int i=0;i<n;i++){
            res[q.front()] = deck[i];
            q.pop_front();
            
            if(!q.empty()){
                int x = q.front();
                q.pop_front();
                q.push_back(x);
            }
            
        }
        return res;
    }
};