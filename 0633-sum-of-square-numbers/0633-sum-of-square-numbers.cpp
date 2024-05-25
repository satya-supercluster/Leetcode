class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=1;
        long long right=sqrt(c);
        if((int)sqrt(c)*(int)sqrt(c)==c) return true;
        while(left<=right){
            long long product=left*left+ right*right;
            if(product>c) right-=1;
            else if (product<c) left+=1;
            else return true;
        }
        return false;
    }
};