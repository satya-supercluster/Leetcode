class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        int n=a.size();
        sort(begin(a),end(a));
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=(long long)a[i]+a[j]+a[k]+a[l];
                    if(sum==t){
                        s.insert({a[i],a[j],a[k],a[l]});
                        k++;
                        l--;
                    }
                    else if(sum<t){
                        k++;
                    }
                    else l--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto&i:s)ans.push_back(i);
        return ans;
    }
};