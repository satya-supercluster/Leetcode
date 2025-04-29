class Solution {
public:
    long long countSubarrays(vector<int>& n, int k) {
        long long mx=(*max_element(n.begin(),n.end()));
        long long ans=0ll,count=0ll,j=0;
        for(int i=0;i<n.size();i++){
            count+=(n[i]==mx)?1:0;
            while(count>=k){
                ans+=n.size()-i;
                count-=(mx==n[j])?1:0;
                j++;
            }
        }
        return ans;
    }
};