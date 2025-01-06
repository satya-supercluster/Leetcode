class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.length();
        vector<int> ans(n,0);
        for(int i{},sum{};i<n;i++){
            for(int j{};j<n;j++){
                if(s[j]=='1'){
                    sum+=abs(i-j);
                }
            }
            ans[i]=sum;
            sum=0;
        }
        return ans;
    }
};