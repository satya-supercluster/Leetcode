class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if( i < 0 && j < 0){
            return true;
        }
        if( j < 0){
            return false;
        }
        if( i < 0){
            while(j >= 0 &&( p[j] =='*') )
                j--;
            return j < 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[j] == '?'){
            // cout << 01 << " " <<  solve(i-1,j-1,s,p) << endl;
            // cout << 02 << " " <<  solve(i,j-1,s,p) << endl;
            return dp[i][j] = (solve(i-1,j-1,s,p,dp));
        }
        if(p[j] == '*'){
            // cout << i << j << " " <<  solve(i-1,j,s,p) << endl;
            // cout << i << j << " " <<  solve(i,j-1,s,p) << endl;
            return  dp[i][j] =(solve(i-1,j,s,p,dp)|solve(i,j-1,s,p,dp));
        }

        if(s[i] == p[j]){
             return dp[i][j] = solve(i-1,j-1,s,p,dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
            vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,s,p,dp);
    }
};