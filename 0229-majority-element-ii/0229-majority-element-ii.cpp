class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto&i:nums)mp[i]++;
        for(auto&[i,j]:mp){
            if(j>nums.size()/3)ans.push_back(i);
        }
        return ans;
    }
};