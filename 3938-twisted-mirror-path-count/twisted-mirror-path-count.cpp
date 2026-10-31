
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 0; i < m; i++) {
            long long left = 0;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    swap(left, dp[j + 1]);
                } else {
                    long long ways = (left + dp[j + 1]) % MOD;
                    left = ways;
                    dp[j + 1] = ways;
                }
            }
        }

        return dp[n];
    }
};
