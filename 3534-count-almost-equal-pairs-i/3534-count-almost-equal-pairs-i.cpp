class Solution {
public:
    bool check(int x, int y) {
    if (x == y) return true;
    string sx = to_string(x);
    string sy = to_string(y);
    // cout<<sx<<" "<<sy<<endl;
    // if (sx.length() != sy.length()) return false;
    for (int i = 0; i < sx.length(); ++i) {
        for (int j = i + 1; j < sx.length(); ++j) {
            string temp = sx;
            swap(temp[i], temp[j]);
            temp.erase(0, temp.find_first_not_of('0'));
            // cout<<sx<<endl;
            if (temp == sy) return true;
        }
    }
    for (int i = 0; i < sy.length(); ++i) {
        for (int j = i + 1; j < sy.length(); ++j) {
            string temp = sy;
            swap(temp[i], temp[j]);
            temp.erase(0, temp.find_first_not_of('0'));
            // cout<<sy<<endl;
            if (temp == sx) return true;
        }
    }
    
    return false;
}
    int countPairs(vector<int>& a) {
        int n=a.size(),ans{};
        for(int i{0};i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(a[i],a[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};