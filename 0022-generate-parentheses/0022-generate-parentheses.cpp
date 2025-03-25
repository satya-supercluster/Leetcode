class Solution {
    vector<string> ans;
public:
    bool check(string&s){
        int c{};
        for(int i{};i<s.size();i++){
            if(s[i]=='(') c++;
            else if(c<=0) return false;
            else c--;
        }
        if(c==0) return true;
        return false;
    }
    vector<string> generateParenthesis(int n) {
        for(int mask{};mask<=(1<<(2*n));mask++){
            string s;
            for(int i{};i<2*n;i++){
                if((mask>>i)&1) s.push_back('(');
                else s.push_back(')');
            }
            // cout<<s<<endl;
            if(check(s)) ans.push_back(s);
        }
        return ans;
    }
};