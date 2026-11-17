
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Precompute cost of making every substring
        // a semi-palindrome
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                cost[i][j] = INT_MAX;

                // Try all proper divisors of len
                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int q = len / d;
                    int changes = 0;

                    // Check each group
                    for (int r = 0; r < d; r++) {

                        // Compare mirrored characters
                        for (int t = 0; t < q / 2; t++) {

                            int left = i + r + t * d;
                            int right = i + r + (q - 1 - t) * d;

                            if (s[left] != s[right]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // DP
        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INT_MAX / 2));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {

                for (int j = 2 * (p - 1); j <= i - 2; j++) {

                    dp[i][p] = min(
                        dp[i][p],
                        dp[j][p - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
