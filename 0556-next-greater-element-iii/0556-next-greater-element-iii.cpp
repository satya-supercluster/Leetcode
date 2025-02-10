class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n!=0){
            int a=n%10;
            digits.push_back(a);
            n=n/10;
        }
        n=digits.size();
        reverse(digits.begin(), digits.end());
        for(int i=0;i<n;i++){
            cout<<digits[i]<<" ";
        }
        cout<<endl;
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if (digits[i]<digits[i+1]){
                idx=i;
                break;
            }

        }
        if(idx==-1) return -1;

        for (int i=n-1;i>=idx;i--){
            if (digits[i]>digits[idx]){
                swap(digits[i],digits[idx]);
                break;
            }
        }
        reverse(digits.begin()+idx+1,digits.end());
        long long  ans=0;
        for (int i=0;i<digits.size();i++){
            ans=10*ans+digits[i];
            if (ans>INT_MAX) return -1;

        }
        return ans;;
        
    }
};