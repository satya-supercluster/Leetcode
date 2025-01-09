class Solution {
public:
    int numDifferentIntegers(string word) {
        int n=word.length();
        int c{};
        if(word[0]=='0'){
            word[0]=' ';
            if(n==1 or (n>=2 and word[1]>='a' and word[1]<='z')) c=1;
        }
        for(int i{};i<n;i++){
            if(word[i]>='a' and word[i]<='z') word[i]=' ';
            else if(word[i]=='0' and i>0 and word[i-1]==' '){
                word[i]=' ';
                if(i==n-1 or (i<n-1 and word[i+1]>='a' and word[i+1]<='z')) c=1;
            }
        }
        set<string>s;
        // cout<<word<<endl;
        string str;
        for(int i{};i<n;i++){
            if(word[i]>='0' and word[i]<='9') str.push_back(word[i]);
            else{
                if(str.length()>0) s.insert(str);
                str="";
            }
        }
        if(str.length()>0) s.insert(str);
        return s.size()+c;
    }
};