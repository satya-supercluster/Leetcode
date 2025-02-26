class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmx{nums[0]},currmn{nums[0]},mx{nums[0]},mn{nums[0]};
        for(int i{1};i<nums.size();i++){
            currmx=max(currmx+nums[i],nums[i]);
            currmn=min(currmn+nums[i],nums[i]);
            mx=max(mx,currmx);
            mn=min(mn,currmn);
        }
        return max(abs(mx),abs(mn));
    }
};