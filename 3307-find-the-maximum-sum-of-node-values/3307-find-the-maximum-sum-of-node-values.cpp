class Solution {
private:
    long long dp[20001][2];
    long long f(int idx,int even,vector<int> &nums,int k) {
        // base cases
        if(idx >= nums.size()) return even? 0 : -1e9;
        if(dp[idx][even] != -1) return dp[idx][even];

        long long take = (nums[idx]^k) + f(idx+1,even^1,nums,k); 
        long long notTake = nums[idx] + f(idx+1,even,nums,k);

        return dp[idx][even] = max(take,notTake);
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        memset(dp,-1,sizeof(dp));
        return f(0,1,nums,k);
    }
};