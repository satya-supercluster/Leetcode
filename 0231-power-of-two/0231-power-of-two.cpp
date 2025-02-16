class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        else if(n==1) return n;
        return (!(n&1)) and isPowerOfTwo(n>>1);
    }
};