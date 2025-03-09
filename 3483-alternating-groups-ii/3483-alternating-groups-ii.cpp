class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        for(int i{};i<k-1;i++) c.push_back(c[i]);
        queue<int> q;
        int ans{};
        for(int i{1};i<k;i++){
            if(c[i]==c[i-1]) q.push(i);
        }
        if(q.empty()) ans++;
        for(int i{k};i<c.size();i++){
            if(c[i]==c[i-1]) q.push(i);
            if(q.size() and q.front()==i-k) q.pop();
            if(q.empty()) ans++;
            if(q.size()==1 and q.front()==i-k+1) ans++;
        }
        return ans;
    }
};