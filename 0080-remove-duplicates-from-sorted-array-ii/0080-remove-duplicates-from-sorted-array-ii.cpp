class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c{},in{},n=nums.size(),prev=-100000;
        for(int i{};i<n;i++){
            if(nums[i]!=prev){
                nums[in++]=nums[i];
                prev=nums[i];
                c=1;
            }
            else if(c<=1){
                nums[in++]=nums[i];
                c++;
            }
            // cout<<c<<" ";
        }
        // cout<<endl;
        return in;
    }
};