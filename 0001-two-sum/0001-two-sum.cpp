class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int i=0,n=v.size(),j=n-1;
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({v[i],i});
        }
        sort(begin(a),end(a));
        while(i<j){
            if(a[i].first+a[j].first==t)return {a[i].second,a[j].second};
            else if(a[i].first+a[j].first>t)j--;
            else i++;
        }
        return {-1,-1};
    }
};