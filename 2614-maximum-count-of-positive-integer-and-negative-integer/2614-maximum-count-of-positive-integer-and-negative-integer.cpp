class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=nums.size()-1;
        int target=0;
        int pos=n;
        int neg=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<0)
            {
                neg=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        left=0;
        right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>0)
            {
                pos=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return max(n-pos,neg+1);
    }
};