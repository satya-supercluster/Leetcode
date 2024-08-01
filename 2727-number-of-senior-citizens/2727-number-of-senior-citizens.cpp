class Solution {
public:
    int countSeniors(vector<string>& v) {
        int ans{};
        for(auto&i:v){
            string s=i.substr(11,2);
            int k=stoi(s);
            if(k>60)ans++;
        }
        return ans;
    }
};