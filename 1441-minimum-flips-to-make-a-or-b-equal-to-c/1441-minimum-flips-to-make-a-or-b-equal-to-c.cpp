class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count{};
        for(int i{};i<32;i++){
            int aBit=(a>>i)&1;
            int bBit=(b>>i)&1;
            int cBit=(c>>i)&1;
            if(cBit==0){
                count+=aBit+bBit;
            }
            else{
                if(aBit==0 and bBit==0) count++;
            }
        }
        return count;
    }
};