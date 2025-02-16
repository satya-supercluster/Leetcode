class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> e,o;
        for(auto&i:nums) if(i%2) o.push_back(i); else e.push_back(i);
        for(int i{};i<nums.size();i++){
            if(i%2){
                nums[i]=o.back();
                o.pop_back();
            }
            else{
                nums[i]=e.back();
                e.pop_back();
            }
        }
        return nums;
    }
};