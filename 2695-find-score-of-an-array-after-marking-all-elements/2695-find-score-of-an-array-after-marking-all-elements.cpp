class Solution {
public:
    long long findScore(vector<int>& a) {
        int n=a.size();
        long long score=0;
        vector<int>vis(n,0);
        vector<pair<int,int>>v;
        for(int i{};i<n;i++){
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end(),[&](const auto&a,const auto&b){
            if(a.first==b.first)return a.second<b.second;
            return a.first<b.first;
        });
        for(int i=0;i<n;i++){
            if(!vis[v[i].second]){
                score+=v[i].first;
                vis[v[i].second]=1;
                if(v[i].second>0) vis[v[i].second-1]=1;
                if(v[i].second<n-1) vis[v[i].second+1]=1;
            }
        }
        return score;
    }
};