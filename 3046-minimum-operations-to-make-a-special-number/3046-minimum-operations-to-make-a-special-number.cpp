class Solution {
public:
    int minimumOperations(string num) {
        int n=num.length();
        vector<int> v;
        vector<string> s={"25","00","75","50"};
        int cnt{},c{};
        for(auto&i:num) if(i!='0') c++;
        for(int t{};t<4;t++){
            cnt=0;
            for(int i{n-1};i>=0;i--){
                if(num[i]==s[t].back()){
                    s[t].pop_back();
                }
                else cnt++;
                if(!s[t].length()){
                    v.push_back(cnt);
                    break;
                }
            }
        }
        // for(auto&i:v)cout<<i<<" ";
        // cout<<endl;
        int k=101;
        if(v.size()) k=*min_element(v.begin(),v.end());
        return min({k,c});
    }
};