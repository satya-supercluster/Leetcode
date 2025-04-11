class Solution {
private:
bool pos(string &s){
    if(s.size()&1){
        return 0;
    }
    int sum=0;
    int sum2=0;
    for(int i=0;i<s.size()/2;i++){
        sum+=(s[i]-'0');
        sum2+=(s[i+s.size()/2]-'0');
    }
    return sum==(sum2);
}
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            cnt+=(pos(s));
        }
        return cnt;
    }
};