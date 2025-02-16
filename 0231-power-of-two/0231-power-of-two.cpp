class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return n;
        return !(n&((long long)n-1));
    }
};