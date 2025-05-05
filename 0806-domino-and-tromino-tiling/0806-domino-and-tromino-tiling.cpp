class Solution {
public:
    vector<vector<int>> dp;
    int n;
    const int mod=1e9+7;
    int numTilings(int n) {
        vector<vector<int>> board(2,vector<int> (n,-1));
        this->n=n;
        int filled=0;
        dp=vector<vector<int>> (n,vector<int> (2,-1));
        return solve(0,board,filled);
    }
    int solve(int i,vector<vector<int>>& board,int filled){
        if(filled==2*n)return 1;
        if(i>=n)return 0;
        if(dp[i][filled%2]!=-1)return dp[i][filled%2];
        int ans=0;
        if(board[0][i]==-1 && board[1][i]==-1){
            //way 1
            board[0][i]=1;
            board[1][i]=1;
            ans=(ans+solve(i+1,board,filled+2))%mod;
            board[0][i]=-1;
            board[1][i]=-1;

            if(i<n-1){
                //way2
                board[0][i]=2;
                board[1][i]=2;
                board[0][i+1]=2;
                ans=(ans+solve(i+1,board,filled+3))%mod;
                board[0][i]=-1;
                board[1][i]=-1;
                board[0][i+1]=-1;

                //way3
                board[0][i]=3;
                board[1][i]=3;
                board[1][i+1]=3;
                ans=(ans+solve(i+1,board,filled+3))%mod;
                board[0][i]=-1;
                board[1][i]=-1;
                board[1][i+1]=-1;

                //way4
                board[0][i]=4;
                board[1][i]=4;
                board[0][i+1]=4;
                board[1][i+1]=4;
                ans=(ans+solve(i+2,board,filled+4))%mod;
                board[0][i]=-1;
                board[1][i]=-1;
                board[0][i+1]=-1;
                board[1][i+1]=-1;
            }
        }else{
            int x= board[0][i]==-1 ? 0 :1;
            if(i<n-1){
                //way5
                board[x][i]=5;
                board[x][i+1]=5;
                ans=(ans+solve(i+1,board,filled+2))%mod;
                board[x][i]=-1;
                board[x][i+1]=-1;

                //way6

                board[x][i]=6;
                board[x][i+1]=6;
                board[!x][i+1]=6;
                ans=(ans+solve(i+2,board,filled+3))%mod;
                board[x][i]=-1;
                board[x][i+1]=-1;
                board[!x][i+1]=-1;
            }
        }
        return dp[i][filled%2]=ans;
    }
};