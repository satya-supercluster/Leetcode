class Solution {
private:
    long long dp[20002][2];
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        memset(dp,0,sizeof(dp));
        // base cases
        dp[n][0] = -1e9;
        dp[n][1] = 0;
        for(int idx=n-1;idx>=0;--idx) {
            for(int even=0;even<2;++even) {
                long long take = (nums[idx]^k) + dp[idx+1][even^1]; 
                long long notTake = nums[idx] + dp[idx+1][even];

                dp[idx][even] = max(take,notTake);
            }
        }
        return dp[0][1];        
    }
};