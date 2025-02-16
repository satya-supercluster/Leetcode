class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        int val{1};
        for(int i{1};i<=n;i++){
            if(val*2==i){
                val=i;
            }
            dp[i]=dp[i-val]+1;
        }
        return dp;
    }
};