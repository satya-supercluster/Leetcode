class Solution {
public:
    int minimumRecolors(string s, int k) {
        int mn{},c{};
        for(int i{};i<k;i++){
            if(s[i]=='W') c++;
        }
        mn=c;
        for(int i{k};i<s.length();i++){
            if(s[i]=='W') c++;
            if(s[i-k]=='W') c--;
            mn=min(mn,c);
        }
        return mn;
    }
};