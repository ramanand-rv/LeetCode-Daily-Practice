#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        // Keep shrinking the string until its length is at most k
        while (s.length() > k) {
            string next = "";

            // Process the string in chunks of size k
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                // Sum the digits in the current chunk (handles the last short
                // chunk)
                for (int j = i; j < min((int)s.length(), i + k); ++j) {
                    sum += s[j] - '0';
                }
                // Append the sum to the next string
                next += to_string(sum);
            }

            // Update s for the next round
            s = next;
        }
        return s;
    }
};