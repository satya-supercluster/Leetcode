class Solution {
public:
    bool canPartition(vector<int>& v) {
        long long sum=accumulate(begin(v),end(v),0ll);
        if(sum&1ll)return false;
        int n=v.size();
        int target=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int i{};i<=n;i++)dp[i][0]=true;
        for(int i{1};i<=n;i++){
            for(int j{1};j<=target;j++){
                if(j>=v[i-1]){
                    int take=dp[i-1][j-v[i-1]];
                    int not_take=dp[i-1][j];
                    dp[i][j]=take||not_take;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};