class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n=a.size(),s=0,e=n-1;
        while(s<=e){
            if(a[s]%2) swap(a[s],a[e]);
            if(a[e]%2==0) swap(a[s],a[e]);
            if(a[s]%2==0) s++;
            if(a[e]%2) e--;
        }
        return a;
    }
};