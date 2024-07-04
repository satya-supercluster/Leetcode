class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.length(),m=s.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*'){
                dp[i][0]=true;
            }
            else break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1])dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')dp[i][j]=dp[i-1][j-1]|dp[i][j-1]|dp[i-1][j];
            }
        }
        // for(int i{};i<=n;i++){
        //     for(int j{};j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};