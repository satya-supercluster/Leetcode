class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[1][0] = dp[0][1] = 0;
        for (int i = 1; i <=n;++i){
            for (int j = 1; j <= m;j++){
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = min(up, left) + mat[i-1][j-1];
            }
        }
        // for(auto&i:dp){
        //     for(auto&j:i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << dp[n][m] << endl;
        return dp[n][m];
    }
};