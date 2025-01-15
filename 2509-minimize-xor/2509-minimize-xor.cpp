class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c=__builtin_popcount(num2);
        int c1=__builtin_popcount(num1);
        if(c==c1) return num1;
        if(c<c1){
            int ans{};
            for(int i{31};i>=0;i--){
                if(num1&(1ll<<i)){
                    if(c>0){
                        ans|=(1ll<<i);
                        c--;
                    }
                }
            }
            return ans;
        }
        else{
            int ans{num1};
            c-=c1;
            for(int i{};i<32;i++){
                if((num1&(1ll<<i))==0){
                    if(c>0){
                        ans|=(1ll<<i);
                        c--;
                    }
                }
            }
            return ans;
        }
        return 0;
    }
};