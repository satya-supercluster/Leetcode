class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        bool dp[n+1][m+1];
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            dp[i][0] = false;
        }
        for(int i = 1; i <= m; i++){
            dp[0][i] = false;
        }
        for(int i = 1; i <= m; i++){
            if(i > 1 && p[i-1] == '*') dp[0][i] |= dp[0][i-2];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    if(j >= 2){
                        if(s[i-1] == p[j-2] || p[j-2] == '.') dp[i][j] = dp[i-1][j];
                        else dp[i][j] = false;
                    }
                    else dp[i][j] = false;
                    if(j > 1){
                        dp[i][j] = dp[i][j] || dp[i][j-2];
                    }
                }
                else if(s[i-1] == p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};