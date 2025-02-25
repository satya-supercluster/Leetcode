class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long int sum{},odd{},ans{};
        for(int i{};i<arr.size();i++){
            sum+=arr[i];
            if(sum%2){
                ans=( ans+i+1-odd)%((int)1e9+7);
                odd++;
            }
            else{
                ans=(ans+odd)%((int)1e9+7);
            }

        }
        return (int)ans;
    }
};