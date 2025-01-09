class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        vector<pair<char,int>>v;
        for(auto&i:word) mp[i]++;
        for(auto&[i,j]:mp)v.push_back({i,j});
        sort(v.begin(),v.end(),[&](auto&a,auto&b){
            return a.second>b.second;
        });
        int c{0},val{1};
        vector<int> cnt(26,0);
        for(int i{};i<v.size();i++){
            c++;
            if(c==9){
                c=1;
                val++;
            }
            cnt[v[i].first-'a']=val;
        }
        int ans{};
        for(auto&i:word){
            ans+=cnt[i-'a'];
        }
        return ans;
    }
};