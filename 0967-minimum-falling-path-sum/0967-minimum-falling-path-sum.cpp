class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; j++)
            {
                int up = dp[i - 1][j];
                int upleft = dp[i-1][j - 1];
                int upright=INT_MAX;
                if(j<n)upright=dp[i-1][j+1];
                dp[i][j] = min({up, upleft,upright}) + mat[i - 1][j - 1];
            }
        }
        long long mn = 1e9;
        for (int i = 0; i <= n; i++)
        {
            mn = min(mn, dp[n][i]);
        }
        return mn;
    }
};