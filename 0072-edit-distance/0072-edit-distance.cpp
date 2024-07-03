class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i < 0){
            return j+1;
        }
        if( j < 0){
            return i+1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = min(solve(i-1,j-1,s,t,dp),1+solve(i-1,j,s,t,dp));
        }
        else{
            return dp[i][j] = min(1+solve(i-1,j-1,s,t,dp),min(1+solve(i-1,j,s,t,dp),1+solve(i,j-1,s,t,dp)));

        }
        // return min(solve(i))
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};