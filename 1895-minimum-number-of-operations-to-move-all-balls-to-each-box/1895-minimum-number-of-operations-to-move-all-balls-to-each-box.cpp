class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.length();
        vector<int> ans(n,0);
        vector<int> pre(n,0),suf(n,0),pc(n,0),sc(n,0);
        if(s[0]=='1') pc[0]=pre[0]=1;
        for(int i{1};i<n;i++){
            pre[i]=pre[i-1]; pc[i]=pc[i-1];
            if(s[i]=='1') pre[i]+=i+1,pc[i]++;
        }
        if(s[n-1]=='1') sc[n-1]=suf[n-1]=1;
        for(int i{n-2};i>=0;i--){
            suf[i]=suf[i+1]; sc[i]=sc[i+1];
            if(s[i]=='1') suf[i]+=(n-i),sc[i]++;
        }
        for(int i{};i<n;i++){
            if(i>0) ans[i]+=(i+1)*pc[i-1]-pre[i-1];
            if(i<n-1) ans[i]+=(n-i)*sc[i+1]-suf[i+1];
        }
        return ans;
    }
};