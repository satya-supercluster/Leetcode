class Solution {
public:
    double power(double a,int n){
        double res=1;
        while(n){
            if(n&1){
                res=res*a;
            }
            a=a*a;
            n>>=1;
        }
        return res;
    }
    double myPow(double x, int n) {
        if(n<0)x=(double)1/x;
        return power(x,abs(n)); 
    }
};