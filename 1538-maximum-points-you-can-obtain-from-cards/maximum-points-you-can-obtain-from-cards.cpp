class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0,r=n-1,maxSum=0;

        for(int i=0;i<k;i++){
            lsum+= cardPoints[i];
            maxSum=max(maxSum,lsum+rsum);
        }

        for(int i=k-1;i>-1;i--){
            lsum-=cardPoints[i];

            rsum+=cardPoints[r];
            r--;
            maxSum=max(maxSum,lsum+rsum);
        }
    return maxSum;
    }
};