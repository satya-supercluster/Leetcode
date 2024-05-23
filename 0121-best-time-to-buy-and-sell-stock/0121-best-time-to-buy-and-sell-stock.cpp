class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<int> mxr(n);
        mxr[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--){
            mxr[i]=max(mxr[i+1],p[i]);
        }
        int ans={};
        for(int i=0;i<n;i++){
            ans=max(ans,mxr[i]-p[i]);
        }
        return ans;
    }
};