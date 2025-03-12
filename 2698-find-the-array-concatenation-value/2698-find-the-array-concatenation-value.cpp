class Solution {
public:
    long long add(int n,int m){
        long long temp=m,c{};
        while(temp) c++,temp/=10;
        return n*1ll*pow(10,c)+m;
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        int i=0,n=nums.size(),j=n-1;
        long long ans{};
        while(i<j){
            ans+=add(nums[i],nums[j]);
            i++;
            j--;
        }
        if(i==j) ans+=nums[i];
        return ans;
    }
};