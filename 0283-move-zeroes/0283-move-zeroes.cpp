class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            nums[i-c]=nums[i];
            if(nums[i]==0)c++;
        }
        for(int i=n-1;i>=0;i--){
            if(c)nums[i]=0,c--;
            else break;
        }
    }
};