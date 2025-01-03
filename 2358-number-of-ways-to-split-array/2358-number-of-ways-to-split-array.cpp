class Solution {
public:
    int waysToSplitArray(vector<int>& v) {
        int n=v.size();
        vector<long long int> pre(n,v[0]);
        for(int i{1};i<n;i++)pre[i]=pre[i-1]+v[i];
        vector<long long int> suf(n,v[n-1]);
        for(int i{n-2};i>=0;i--){
            suf[i]=suf[i+1]+v[i];
        }
        // for(auto&i:pre)cout<<i<<" ";
        // cout<<endl;
        
        // for(auto&i:suf)cout<<i<<" ";
        // cout<<endl;

        int ans{};
        for(int i{0};i<n-1;i++){
            if(pre[i]>=suf[i+1]) ans++;
        }
        return ans;
    }
};