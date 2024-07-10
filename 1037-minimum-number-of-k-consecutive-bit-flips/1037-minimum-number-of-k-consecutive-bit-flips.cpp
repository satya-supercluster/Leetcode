class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flipped{},ans{};
        vector<int> isF(n,0);
        for(int i=0;i<n;i++){
            if(i>=k)flipped^=isF[i-k];
            if(nums[i]==flipped){
                if((i+k)>n)return -1;
                ans+=1;
                isF[i]=1;
                flipped^=1;
            }
            // cout<<flipped<<" ";
        }
        return ans;
    }
};