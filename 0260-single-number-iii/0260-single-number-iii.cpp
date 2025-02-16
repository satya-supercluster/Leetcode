class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x{};
        for(auto&i:nums)x^=i;
        int ind{-1};
        ind=x&(-(unsigned)x);
        int x1{},x2{};
        for(auto&i:nums){
            if(i&ind) x1^=i;
            else x2^=i;
        }
        return {x1,x2};
    }
};