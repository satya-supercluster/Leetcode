class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> v;
        vector<pair<int,int>> notes (26,make_pair(10000000,-1));
        int n = s.size();
        for(int i=0;i<n;i++){
            int ind = s[i]-'a';
            notes[ind].first = min(notes[ind].first,i);
            notes[ind].second = max(notes[ind].second,i);
        }
        for(int i=0;i<26;i++){
            if(notes[i].second!=-1){
                int maxx = notes[i].second;
                int minn = notes[i].first;
                for(int ind=minn;ind<=maxx;ind++){
                    maxx = max(maxx,notes[s[ind]-'a'].second);
                    minn = min(minn,notes[s[ind]-'a'].first);
                }
                if(minn==notes[i].first){
                    v.push_back({minn,maxx});
                }
            }
        }
        sort(v.begin(),v.end(),[](vector<int>& a,vector<int>& b){
            return ((a[1]-a[0])<(b[1]-b[0]));
        });
        set<pair<int,int>> myset;
        vector<string> ans;
        for(auto x : v){
            if(!myset.empty()){
                auto it = upper_bound(myset.begin(),myset.end(),make_pair(x[0],x[1]));
                if(it!=myset.begin()){
                    auto back = *(prev(it));
                    if(back.second>=x[0]) continue;
                }
                if(it!=myset.end()){
                    auto nex = (*(it));
                    if(nex.first<=x[1]) continue;
                }
            }
            myset.insert(make_pair(x[0],x[1]));
            string curr="";
            for(int j=x[0];j<=x[1];j++){
                curr+=s[j];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};