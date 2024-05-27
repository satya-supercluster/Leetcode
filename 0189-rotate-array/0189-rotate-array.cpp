class Solution {
public:
    void rotate(vector<int>& v, int k) {
        vector<int> t;
        int n=v.size();
        k%=n;
        for(int i=n-k;i<n;i++){
            t.push_back(v[i]);
        }
        for(int i=n-1;i>=k;i--){
             v[i]=v[i-k];
        } 
        for(int i=0;i<k;i++){
             v[i]=t[i];
        }
    }
};