class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        map<int,int> mp;
        stack<int> st;
        for(int i{n-1};i>=0;i--){
            while(st.size() and st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()) mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(auto&i:nums1)i=mp[i];
        return nums1;
    }
};