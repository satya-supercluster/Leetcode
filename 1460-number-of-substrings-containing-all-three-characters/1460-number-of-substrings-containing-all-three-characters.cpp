class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int i{},n=s.length(),ans{};
        for(int j{};j<n;j++){
            mp[s[j]]++;
            while(mp.size()==3 and i<j){
                ans+=n-j;
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};