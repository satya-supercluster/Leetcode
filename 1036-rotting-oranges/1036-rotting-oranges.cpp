class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int orangesRotting(vector<vector<int>> g) {
        int m=g.size(),n=g[0].size(),on{};
        queue<pair<int,int>>q;
        for(int i{};i<m;i++){
            for(int j{};j<n;j++){
                if(g[i][j]==2)q.push({i,j});
                if(g[i][j]==1)on++;
            }
        }
        if(q.size()==0 and (!on))return 0;
        int ans{-1};
        while(q.size()){
            int sz=q.size();
            ++ans;
            for(int k{};k<sz;k++){
            auto ele=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=ele.first+dir[i].first;
                int y=ele.second+dir[i].second;
                if(x>=0 and x<m and y>=0 and y<n and g[x][y]==1){
                    g[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        }
        for(int i{};i<m;i++){
            for(int j{};j<n;j++){
                if(g[i][j]==1)return -1;
                // cout<<g[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};