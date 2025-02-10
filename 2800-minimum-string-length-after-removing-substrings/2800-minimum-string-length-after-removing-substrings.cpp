class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i{};i<s.length();i++){
            if(st.size() and ((s[i]=='B' and st.top()=='A') or (s[i]=='D' and st.top()=='C'))) st.pop();
            else st.push(s[i]);
        }
        string s2;
        while(!st.empty()){
            s2.push_back(st.top());
            st.pop();
        }
        reverse(s2.begin(),s2.end());
        return s2.length();
    }
};