class Solution {
public:
    bool isPerfectSquare(int num) {
        long long s=1,e=num,mid;
        while(s<=e){
            mid=s+(e-s)/2ll;
            if(mid*1ll*mid==num)return true;
            else if(mid*1ll*mid<num)s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};