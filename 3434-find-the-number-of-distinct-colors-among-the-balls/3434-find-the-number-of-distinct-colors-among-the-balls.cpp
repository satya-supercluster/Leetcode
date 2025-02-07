class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& q) {
        map<int,int> mp,cmp;
        vector<int> ans;
        for(auto&v:q){
            int pos=v[0];
            int col=v[1];
            if(mp.count(pos)){
                cmp[mp[pos]]--;
                if(cmp[mp[pos]]==0) cmp.erase(mp[pos]);
                cmp[col]++;
                mp[pos]=col;
            }
            else{
                mp[pos]=col;
                cmp[col]++;
            }
            ans.push_back(cmp.size());
        }
        return ans;
    }
};