class Solution {
public:
    int hammingWeight(int n) {
        int ans{};
        while(n>0){
            n-=n&(-n);
            ans++;
        }
        return ans;
    }
};