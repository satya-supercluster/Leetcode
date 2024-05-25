class Solution {
public:
    int mySqrt(int x) {
        long long s=1,e=x,mid,ans{};
        while(s<=e){
            mid=s+(e-s)/2ll;
            if(1ll*mid*mid==x)return mid;
            else if(1ll*mid*mid<x){
                ans=mid;
                s=mid+1ll;
            }
            else{
                e=mid-1ll;
            }
        }
        return ans;
    }
};