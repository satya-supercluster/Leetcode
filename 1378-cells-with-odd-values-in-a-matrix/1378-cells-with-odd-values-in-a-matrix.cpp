class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& in) {
        vector<int>r(m,0),c(n,0);
        for(auto&p:in){
            r[p[0]]++;
            c[p[1]]++;
        }
        int ans{};
        for(int i=0;i<m;i++){
            for(int j{};j<n;j++){
                if((r[i]+c[j])%2)ans++;
            }
        }
        return ans;
    }
};