class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),k=arr.size();
        vector<int> r(n,0),c(m,0);
        map<int,pair<int,int>>mp;
        for(int i{};i<n;i++){
            for(int j{};j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i{};i<k;i++){
            auto pi=mp[arr[i]];
            r[pi.first]++;
            if(r[pi.first]==m) return i;
            c[pi.second]++;
            if(c[pi.second]==n) return i;
        }
        return k-1;
    }
};