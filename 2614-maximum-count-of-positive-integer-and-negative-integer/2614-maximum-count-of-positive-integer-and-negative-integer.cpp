class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos{},neg{};
        for(auto&i:nums) if(i>0) pos++; else if(i<0) neg++;
        return max(pos,neg);
    }
};