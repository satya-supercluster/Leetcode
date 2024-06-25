class Solution {
public:
    int findTargetSumWays(vector<int>& v, int target) {
        int totalSum = 0;
        for (int num : v) totalSum += num;
        if (abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2 != 0) return 0;
        target = (totalSum + target) / 2;
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i{1};i<=n;i++){
            for(int j{0};j<=target;j++){
                if(j>=v[i-1]){
                    int take=dp[i-1][j-v[i-1]];
                    int not_take=dp[i-1][j];
                    dp[i][j]=take+not_take;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};