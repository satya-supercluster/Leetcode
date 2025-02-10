class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i{};i<s.length();i++){
            if(s[i]>='0' and s[i]<='9') st.pop();
            else st.push(s[i]);
        }
        string s2;
        while(!st.empty()){
            s2.push_back(st.top());
            st.pop();
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
};