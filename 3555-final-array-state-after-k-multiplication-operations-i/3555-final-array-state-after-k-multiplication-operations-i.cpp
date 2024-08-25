class Solution {
public:
    vector<int> getFinalState(vector<int>& a, int k, int m) {
        int min=101,ind=-1,n=a.size();
        for(int i{};i<k;i++){
            min=a[0];
            ind=0;
            for(int j{0};j<n;j++){
                if(min>a[j]){
                    min=a[j];
                    ind=j;
                }
            }
            a[ind]=a[ind]*m;
        }
        return a;
    }
};