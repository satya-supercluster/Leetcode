class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<char,char>>st;
        int cnt{};
        for(int i{};i<s1.length();i++){
            if(s1[i]!=s2[i]){
                st.push_back({s1[i],s2[i]});
                cnt++;
            }
        }
        if(!cnt) return true;
        if(cnt==2 and st.size()==2 and st[0].first==st[1].second and st[1].first==st[0].second) return true;
        return false;
    }
};