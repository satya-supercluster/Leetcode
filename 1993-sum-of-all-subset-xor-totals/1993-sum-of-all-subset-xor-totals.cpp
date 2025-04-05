class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans{};
        for(int mask{};mask<(1<<n);mask++){
            int x{};
            for(int i{};i<n;i++){
                if((mask>>i)&1){
                    x^=nums[i];
                }
            }
            ans+=x;
        }
        return ans;
    }
};