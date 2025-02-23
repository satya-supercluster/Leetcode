class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n=rewardValues.size();
        vector<int> dp(4001,0);
        sort(rewardValues.begin(),rewardValues.end());
        for(int i=n-1;i>=0;i--){
            for(int x=3999;x>=0;x--){
                int sum=0;
                if(rewardValues[i]>x){
                    sum=max(dp[x],rewardValues[i]+dp[x+rewardValues[i]]);
                }
                else{
                    sum=dp[x];
                }
                dp[x]=sum;
            }
        }
        return dp[0];
    }

};