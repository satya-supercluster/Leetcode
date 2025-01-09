class Bitset {
    string bits;
    int c0,c1,n;
    bool flp;
public:
    Bitset(int size) {
        this->n=size;
        bits.resize(n);
        for(auto&i:bits)i='0';
        this->c0=n;
        this->c1=0;
        this->flp=false;
    }
    
    void fix(int idx) {
        if(!flp){
            if(bits[idx]=='0'){
                bits[idx]='1';
                c1++;
                c0--;
            }
        }
        else{
            if(bits[idx]=='1') {
                bits[idx]='0';
                c0++;
                c1--;
            }
        }
    }
    
    void unfix(int idx) {
        if(flp){
            if(bits[idx]=='0') {
                bits[idx]='1';
                c1++;
                c0--;
            }
        }
        else{
            if(bits[idx]=='1'){
                bits[idx]='0';
                c0++;
                c1--;
            }
        }
    }
    
    void flip() {
        flp=(!flp);
    }
    
    bool all() {
        if(flp){
            if(c0==n) return true;
        }
        else if(c1==n) return true;
        return false;
        // cout<<bits<<endl;
    }
    
    bool one() {
        if(flp){
            if(c0>0) return true;
        }
        else if(c1>0) return true;
        return false;
    }
    
    int count() {
        if(flp){
            return c0;
        }
        return c1;
    }
    
    string toString() {
        if(flp){
            string str;
            for(auto&i:bits) str.push_back((!(i-'0'))+'0');
            return str;
        }
        return bits;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */