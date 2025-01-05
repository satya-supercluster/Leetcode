class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sf) {
        int n=s.length();
        vector<long long int> v(n+1,0);
        for(auto&l:sf){
            if(l[2]){
                v[l[0]]++;
                v[l[1]+1]--;

            }
            else{
                v[l[0]]--;
                v[l[1]+1]++;
            }
        }
        for(int i{1};i<=n;i++){
            v[i]=(v[i]+v[i-1]);
        }
        for(int i{0};i<n;i++){
            v[i]=(v[i])%26ll;
            char c=s[i];
            c='a'+(((int)c-'a')+v[i]+26)%26;
            // cout<<s[i]<<" "<<c<<" "<<v[i]<<endl;
            s[i]=c;
        }
        return s;
    }
};