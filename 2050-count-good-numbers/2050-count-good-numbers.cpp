class Solution {
    int mod=(int)1e9+7;
public:
    long long power(long long a,long long b){
        long long res=1ll;
        while(b){
            if(b&1ll)
                res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1ll;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long ans = power(5ll,even)%mod;
        long long ans1 = power(4ll,odd)%mod;
        long long finall = (ans*ans1)%mod;
        return (int) finall;
    }
};