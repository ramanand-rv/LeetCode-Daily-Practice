class Solution {
private:
    const int MOD = 1e9 + 7;

    bool isValid(int i, int j, int n, vector<string>& board) {
        return i < n && j < n && board[i][j] != 'X';
    }

    int getValue(int i, int j, vector<string>& board) {
        char ch = board[i][j];
        if (ch >= '1' && ch <= '9') return ch - '0';
        return 0;  
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        // dp[i][j] = {maxScore, ways} from (i,j) to destination
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));

        dp[n - 1][n - 1] = {0, 1};

        // Process cells in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Skip blocked cells or the destination 
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }

                // Check all 3 possible moves: down, right, diagonal
                int bestScore = -1;
                long long totalWays = 0;

                // Down
                if (isValid(i + 1, j, n, board) && dp[i + 1][j].first != -1) {
                    int score = dp[i + 1][j].first;
                    if (score > bestScore) {
                        bestScore = score;
                        totalWays = dp[i + 1][j].second;
                    } else if (score == bestScore) {
                        totalWays = (totalWays + dp[i + 1][j].second) % MOD;
                    }
                }

                // Right
                if (isValid(i, j + 1, n, board) && dp[i][j + 1].first != -1) {
                    int score = dp[i][j + 1].first;
                    if (score > bestScore) {
                        bestScore = score;
                        totalWays = dp[i][j + 1].second;
                    } else if (score == bestScore) {
                        totalWays = (totalWays + dp[i][j + 1].second) % MOD;
                    }
                }

                // Diagonal
                if (isValid(i + 1, j + 1, n, board) && dp[i + 1][j + 1].first != -1) {
                    int score = dp[i + 1][j + 1].first;
                    if (score > bestScore) {
                        bestScore = score;
                        totalWays = dp[i + 1][j + 1].second;
                    } else if (score == bestScore) {
                        totalWays = (totalWays + dp[i + 1][j + 1].second) % MOD;
                    }
                }

                // If no valid move found, this cell is unreachable
                if (bestScore == -1) continue;

                // Add current cell's value to the best score
                int currentValue = getValue(i, j, board);
                dp[i][j] = {bestScore + currentValue, (int)totalWays};
            }
        }

        if (dp[0][0].first == -1) {
            return {0, 0};
        }

        return {dp[0][0].first, dp[0][0].second};
    }
};