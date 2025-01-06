class Solution {
public:
    int splitNum(int num) {
        map<int,int> mp;
        while(num){
            mp[num%10]++;
            num/=10;
        }
        int x{},y{},p=true;
        for(auto&[i,j]:mp){
            for(int k{};k<j;k++){
                if(p){
                    x=x*10ll+i; p=!p;
                }
                else{
                    y=y*10ll+i; p=!p;
                }
            }
        }
        return x+y;
    }
};