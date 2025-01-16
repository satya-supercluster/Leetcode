class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x{};
        int n=nums1.size();
        int m=nums2.size();
        if(n&1){
            for(int i{};i<m;i++) x^=nums2[i];
        }
        if(m&1){
            for(int i{};i<n;i++) x^=nums1[i];
        }
        return x;
    }
};