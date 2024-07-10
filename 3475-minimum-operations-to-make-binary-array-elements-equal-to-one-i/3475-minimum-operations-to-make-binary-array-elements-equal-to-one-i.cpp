class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flipped{},ans{};
        vector<int> isF(n,0);
        for(int i=0;i<n;i++){
            if(i>=3)flipped^=isF[i-3];
            if(nums[i]==flipped){
                if((i+3)>n)return -1;
                ans+=1;
                isF[i]=1;
                flipped^=1;
            }
            // cout<<flipped<<" ";
        }
        return ans;
    }
};