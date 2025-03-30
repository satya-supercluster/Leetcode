class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int n=s.length();

        vector<int>mp(26,-1);
        for(int i=0;i<n;i++) mp[s[i]-'a']=i;

        int x=0,i=0,j=0;
        while(x<n){
            j=max(j,mp[s[x]-'a']);
            if(x==j){
                ans.push_back(j-i+1);
                i=j+1;
            }
            x++;
        }
        return ans;
    }
};