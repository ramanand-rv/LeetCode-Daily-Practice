class Solution {
public:
    int numberOfSubstrings(string s) {
/*        int n = s.size();
        int left = 0;
        int cnt = 0;
        int a = 0, b = 0, c = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == 'a')
                a++;
            else if (s[right] == 'b')
                b++;
            else
                c++;

            while (a > 0 && b > 0 && c > 0) {
                cnt += (n - right);

                if (s[left] == 'a')
                    a--;
                else if (s[left] == 'b')
                    b--;
                else
                    c--;

                left++;
            }
        }

        return cnt;
*/
        int seen[3] = {-1, -1, -1};
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            seen[s[i] - 'a'] = i;
            
            if (seen[0] != -1 && seen[1] != -1 && seen[2] != -1) {
                
                int minPos = std::min({seen[0], seen[1], seen[2]}); 
                count += (minPos + 1);
            }
        }
        
        return count;
    }
};