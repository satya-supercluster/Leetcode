class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> c;
        map<int,int> mpa,mpb;
        int cnt{};
        set<int> st;
        for(int i{};i<a.size();i++){
            mpa[a[i]]++;
            mpb[b[i]]++;
            if(mpb.count(a[i])){
                st.insert(a[i]);
            }
            if(mpa.count(b[i])){
                st.insert(b[i]);
            }
            // cout<<a[i]<<" "<<b[i]<<endl;
            c.push_back(st.size());
        }
        return c;
    }
};