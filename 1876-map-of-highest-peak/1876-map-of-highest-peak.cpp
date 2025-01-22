class Solution {
    vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        queue<pair<int,int>>q;
        int n=w.size(),m=w[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i{};i<n;i++){
            for(int j{};j<m;j++){
                if(w[i][j]==1) {q.push({i,j}); vis[i][j]=true; w[i][j]=0;}
            }
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i{};i<sz;i++){
                auto pi=q.front();
                q.pop();
                int x1=pi.first;
                int y1=pi.second;
                for(int k{};k<4;k++){
                    int x=x1+dir[k].first;
                    int y=y1+dir[k].second;
                    if(x>=0 and x<n and y>=0 and y<m and (!vis[x][y])){
                        w[x][y]=w[x1][y1]+1;
                        vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
        return w;
    }
};