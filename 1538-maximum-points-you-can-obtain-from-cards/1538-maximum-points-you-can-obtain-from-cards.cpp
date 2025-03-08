class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        if(k>n)return 0;
        long long lsum=0, rsum=0, sum=0;
        for(int i=0; i<k; i++){
            lsum+=cardPoints[i];
        }
        sum=lsum;
        int right=n-1;
        for(int i=k-1; i>=0; i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[right];
            right--;
            sum=max(sum, lsum+rsum);
        }
        return sum;
    }
};