class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string ans,t;
        for(auto&i:s){
            if(i==' '){
                if(t.length()!=0){
                    v.push_back(t);
                    t.clear();
                }
            }
            else{
                t.push_back(i);
            }
        }
        if(t.length()!=0){
            v.push_back(t);
            t.clear();
        }
        for(int i=v.size()-1;i>=0;i--){
            ans.append(v[i]);
            ans.append(" ");
        }
        ans.pop_back();
        return ans;
    }
};