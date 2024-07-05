class Solution {
public:
    
    int dp[100005];
    int mod = 1e9+7;
    long long f(int i,string &s,int n){
        if(i>=n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        long long ways=0;
        if(s[i]=='*'){
             ways = (ways%mod+9*f(i+1,s,n)%mod)%mod;
             if(i<n-1){
                 char ch = s[i+1];
                 if(ch!='*' and ch>='0' and ch<='6'){
                      ways = (ways%mod+2*f(i+2,s,n)%mod)%mod;
                 }else if(ch!='*' and ch>='7') {
                      ways = (ways%mod+f(i+2,s,n)%mod)%mod;
                 }else {
                      ways = (ways%mod+15*f(i+2,s,n)%mod)%mod;
                 }
             }
        }else{
            ways = (ways%mod+f(i+1,s,n)%mod)%mod;
            if(i<n-1){
                if(s[i+1]!='*' and stoi(s.substr(i,2))>=10 and stoi(s.substr(i,2))<=26){
                     ways = (ways%mod+f(i+2,s,n)%mod)%mod;
                }
                else if(s[i+1]=='*' and s[i]=='1'){
                     ways = (ways%mod+9*f(i+2,s,n)%mod)%mod;
                }
                else if(s[i+1]=='*' and s[i]=='2'){
                     ways = (ways%mod+6*f(i+2,s,n)%mod)%mod;
                }
            }
        }
        
        return dp[i] = ways%mod;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return f(0,s,n);
    }
};