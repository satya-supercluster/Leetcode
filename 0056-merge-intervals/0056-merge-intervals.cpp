class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> da(10001,0);
        vector<int> pre(10001,0);
        set<vector<int>>st;
        for(auto k:intervals){
            int i=k[0],j=k[1];
            da[i]++;
            da[j]--;
        }
        int sum{},prev=-1,p=0;
        for(int i=0;i<=10000;i++){
            int k=sum;
            sum+=da[i];
            pre[i]=sum;
            if(sum>0 and k==0){
                prev=i;
                p=1;
            }
            else if(p and sum==0){
                st.insert({prev,i});
                p=0;
            }
        }
        for(auto k:intervals){
            int i=k[0],j=k[1];
            if(i==j and pre[i]==0 and da[i]==0){
                st.insert({i,i});
            }
        }
        vector<vector<int>> ans(begin(st),end(st));
        return ans;
    }
};