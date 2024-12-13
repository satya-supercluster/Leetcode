class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector<vector<int>>radj(n),badj(n);
        vector<int>ans(n,110);
        ans[0]=0;
        for(auto&redge:re){
            radj[redge[0]].push_back(redge[1]);
            // radj[redge[1]].push_back(redge[0]);
        }
        for(auto&bedge:be){
            badj[bedge[0]].push_back(bedge[1]);
            // badj[bedge[1]].push_back(bedge[0]);
        }
        vector<vector<int>>vis(n,vector<int>(2,0));
        vis[0][0]=1;
        vis[0][0]=2;
        queue<pair<int,int>>q;
        for(auto&i:radj[0]){
            q.push({i,0});
            vis[i][0]=true;
        }
        for(auto&i:badj[0]){
            q.push({i,1});
            vis[i][1]=true;
        }
        int i=1;
        while(!q.empty()){
            int sz=q.size();
            for(int p{};p<sz;p++){
                auto ele=q.front();
                q.pop();
                ans[ele.first]=min(i,ans[ele.first]);
                if(ele.second){
                    for(auto&kk:radj[ele.first]){
                        if(!vis[kk][0]){
                            q.push({kk,0});
                            vis[kk][0]=1;
                        }

                    }
                }
                else{
                    for(auto&kk:badj[ele.first]){
                        if(!vis[kk][1]){
                            q.push({kk,1});
                            vis[kk][1]=1;
                        }
                    }
                }
            }
            i++;
        }
        for(auto&i:ans){
            if(i==110)i=-1;
        }
        return ans;
    }
};