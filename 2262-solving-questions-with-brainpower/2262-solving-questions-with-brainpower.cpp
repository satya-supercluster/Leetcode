class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long > v(n, 0);
        v[n-1] = questions[n-1][0];
        for(int i = n-2; i >= 0; i--){
            int p = questions[i][0];
            int b = questions[i][1];
            int next = min(i+b+1, n);
            long long x = p + (next < n? v[next] : 0);
            long long y = v[i+1];
            v[i] = max(x, y); 
        }
        return v[0];
    }
};