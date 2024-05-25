class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum{},n=nums.size();
        for(int i=1;i<=n;i++){
            if(n%i==0)sum+=1ll*nums[i-1]*nums[i-1];
        }
        return sum;
    }
};