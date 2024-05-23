class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int in=-1;
        int n=a.size();
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                in=i;
                break;
            }
        }
        if(in==-1){
            sort(begin(a),end(a));
            return;
        }
        int se=in+1;
        for(int i=n-1;i>in;i--){
            if(a[i]>a[in] and a[i]<a[se]){
                se=i;
            }
        }
        swap(a[in],a[se]);
        sort(begin(a)+in+1,end(a));
        return;
    }
};