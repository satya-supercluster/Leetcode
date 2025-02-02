class Solution {
public:
    string removeDigit(string num, char d) {
        int n=num.length(),l{-1};
        string s;
        for(int i{};i<n;i++){
            if(num[i]==d){
                l=i;
                if(i==n-1){
                    return s;
                }
                else if(num[i+1]>num[i]){
                    s+=num.substr(i+1);
                    return s;
                }
                else if(num[i+1]<=num[i]){
                    s.push_back(num[i]);
                }
            }
            else s.push_back(num[i]);
        }
        string str;
        for(int i{};i<n;i++) if(i!=l) str.push_back(num[i]);
        return str;
    }
};