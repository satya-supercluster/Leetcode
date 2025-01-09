class Solution {
public:
    bool winnerOfGame(string v) {
        int ca{},cb{};
        int curr{0};
        for(int i{1};i<v.size()-1;i++){
            if(v[i]=='A' and v[i+1]=='A' and v[i-1]=='A'){
                ca++;
            }
            if(v[i]=='B' and v[i+1]=='B' and v[i-1]=='B'){
                cb++;
            }
        }
        if(ca<=cb) return false;
        return true;
    }
};