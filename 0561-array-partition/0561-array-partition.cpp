class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> mp(20001,0);
        for(size_t i=0;i<nums.size();i++)
        {
            mp[nums[i]+10000]++;
        }
        int ret=0;
        int flag=0;
        for(size_t i=0;i<20001;){
            if((mp[i]>0)&&(flag==0)){
                ret=ret+i-10000;
                flag=1;
                mp[i]--;
            }else if((mp[i]>0)&&(flag==1)){
                mp[i]--;
                flag=0;
            }else i++;
        }
        return ret;
    }
};