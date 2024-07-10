class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<pair<int,int>> dir={{0,1},{1,0},{1,1}};
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mn=1000;
                for(auto p:dir){
                    int x=p.first+i;
                    int y=p.second+j;
                    mn=min(mn,dp[x][y]);
                }
                dp[i][j]=mn+(mat[i][j]-'0');
                if((mat[i][j]-'0')==0)dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        // for(auto&i:dp){
        //     for(auto&j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans*ans;
    }
};