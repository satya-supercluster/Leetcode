class Solution {
public:
    string fourthDigit(int n){
        string s="";
        for(int i{};i<n;i++) s+='M';
        return s;
    }
    string thirdDigit(int n){
        if(n<4){
            string s="";
            for(int i{};i<n;i++) s+='C';
            return s;
        }
        else if(n==4) return "CD";
        else if(n<9){
            string s="D";
            for(int i{};i<n-5;i++) s+='C';
            return s;
        }
        return "CM"; // 9
        
    }
    string secondDigit(int n){
        if(n<4){
            string s="";
            for(int i{};i<n;i++) s+='X';
            return s;
        }
        else if(n==4) return "XL";
        else if(n<9){
            string s="L";
            for(int i{};i<n-5;i++) s+='X';
            return s;
        }
        return "XC"; // 9
    }
    string firstDigit(int n){
        if(n<4){
            string s="";
            for(int i{};i<n;i++) s+='I';
            return s;
        }
        else if(n==4) return "IV";
        else if(n<9){
            string s="V";
            for(int i{};i<n-5;i++) s+='I';
            return s;
        }
        return "IX"; // 9
    }
    string intToRoman(int num) {
        string ans="";
        int f,s,t,fr;
        f=num%10;
        s=(num/10)%10;
        t=(num/100)%10;
        fr=(num/1000)%10;
        ans+=fourthDigit(fr);
        ans+=thirdDigit(t);
        ans+=secondDigit(s);
        ans+=firstDigit(f);
        return ans;
    }
};