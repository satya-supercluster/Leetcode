class Solution {
public:
    int countBalls(int l, int h) {
        unordered_map<int,int> mp;
        for(int i=l;i<=h;i++){
            int t=i;
            int c=0;
            while(t){
                c+=t%10;
                t/=10;
            }
            mp[c]++;
        }
        int ans{};
        for(auto&[i,j]:mp){
            ans=max(ans,j);
        }
        return ans;
    }
};