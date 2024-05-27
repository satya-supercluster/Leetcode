class Solution {
public:
    bool check(vector<int>& nums) {
        int p{-1};
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                p=i;
            }
        }
        if(p==-1)return true;
        vector<int> v;
        for(int i=p;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        for(int i=0;i<p;i++){
            v.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++){
            if(v[i]<v[i-1])return false;
        }
        return true;
    }
};