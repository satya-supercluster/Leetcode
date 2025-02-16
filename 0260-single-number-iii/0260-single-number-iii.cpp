class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x{};
        for(auto&i:nums)x^=i;
        int ind{-1};
        ind=x&(-(unsigned)x);
        vector<int> f,s;
        for(auto&i:nums){
            if(i&ind)f.push_back(i);
            else s.push_back(i);
        }
        int x1=x;
        for(auto&i:f)x1^=i;
        int x2=x;
        for(auto&i:s)x2^=i;
        return {x1,x2};
    }
};