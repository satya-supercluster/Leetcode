class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int freq[210]={0};
        for(auto&i:nums){
            freq[i+100]++;
        }
        int un{},k{};
        for(int i{};i<210;i++){
            if(freq[i]!=0){
                un++;
                nums[k++]=i-100;
            }
        }
        return un;
    }
};