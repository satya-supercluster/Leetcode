class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr{},c{};
        for(auto&i:nums) maxOr|=i;
        int n=nums.size();
        int sz=1ll<<n;
        for(int j{};j<sz;j++){
            int oor{};
            for(int k{};k<n;k++){
                if(j&(1ll<<k)){
                    oor|=nums[k];
                }
            }
            if(oor==maxOr) c++;
        }
        return c;
    }
};