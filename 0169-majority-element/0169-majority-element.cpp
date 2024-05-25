class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me=nums[0];
        int c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==me)c++;
            else c--;
            if(c==0){
                me=nums[i];
                c=1;
            }
        }
        return me;
    }
};