class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flipped{},ans{};
        // vector<int> isF(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==flipped){
                ans+=1;
                flipped^=1;
            }
            // cout<<flipped<<" ";
        }
        return ans;
    }
};