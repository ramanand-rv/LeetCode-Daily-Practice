class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        // sort
        sort(sorted.begin(), sorted.end());
        
        // Remove duplicates
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        
        // Replace each element with its rank
        for (int i = 0; i < arr.size(); i++) {
            // lower_bound returns iterator to first element >= arr[i]
            // Subtract begin to get 0-based index, then +1 for rank
            arr[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
        }
        
        return arr;
    }
};