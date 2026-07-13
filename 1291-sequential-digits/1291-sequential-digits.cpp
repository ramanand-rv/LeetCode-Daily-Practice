class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        // Try every possible starting digit
        for (int start = 1; start <= 9; ++start) {
            int num = start;
            
            // Append digits sequentially
            for (int next = start + 1; next <= 9; ++next) {
                num = num * 10 + next;

                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};