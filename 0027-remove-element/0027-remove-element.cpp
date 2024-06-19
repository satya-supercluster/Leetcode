class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int in=0;
        int n=nums.size();
        for(int i{};i<n;i++){
            if(nums[i]!=val){
                nums[in++]=nums[i];
            }
        }
        return in;
    }
};