class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=words.size();
        vector<string> pre(n,words[0]);
        for(int i{1};i<n;i++){
            pre[i]=pre[i-1]+words[i];
        }
        for(auto&i:pre) if(i==s) return true;
        return false;
    }
};